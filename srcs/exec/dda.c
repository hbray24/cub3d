/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:01:08 by hbray             #+#    #+#             */
/*   Updated: 2026/06/03 10:08:27 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_touch(t_dda *dda, t_cub *cub)
{
	if (dda->map_x < 0 || dda->map_y < 0 || !cub->para->map[dda->map_y]
		|| !cub->para->map[dda->map_y][dda->map_x])
	{
		cub->dda.texture = NORTH;
		return (1);
	}
	if (cub->para->map[dda->map_y][dda->map_x] == 'D' && get_door_lvl(cub,
			dda->map_x, dda->map_y) < 1.0)
	{
		cub->dda.texture = DOOR;
		return (1);
	}
	if (cub->para->map[dda->map_y][dda->map_x] == '1'
		|| cub->para->map[dda->map_y][dda->map_x] == 'X')
	{
		if (cub->para->map[dda->map_y][dda->map_x] == 'X')
			cub->dda.texture = EXIT;
		return (1);
	}
	return (0);
}

void	run_dda(t_dda *dda, t_cub *cub)
{
	int	touch;

	touch = 0;
	while (touch == 0)
	{
		step_dda(dda);
		touch = check_touch(dda, cub);
	}
}

void	calcul_wall(float ray_dist, t_cub *cub, float start_x, int i)
{
	float	dist;
	int		start_y;
	int		end;

	dist = ray_dist * 64;
	dist = dist * cos(start_x - cub->player->angle);
	if (dist < 0.1)
		dist = 0.1;
	cub->dda.wall_height = (64 / dist) * (cub->screen.width / 2) / (tan(PI
				/ 6));
	start_y = (cub->screen.height - cub->dda.wall_height) / 2;
	end = start_y + cub->dda.wall_height;
	if (start_y < 0)
		start_y = 0;
	if (end > cub->screen.height)
		end = cub->screen.height;
	draw_ceiling(start_y, i, cub);
	draw_wall(start_y, end, i, cub);
	draw_floor(end, i, cub);
}

void	draw_line(t_player *player, t_cub *cub, float start_x, int i)
{
	float	ray_dist;
	float	wall_x;

	init_dda_step(start_x, &cub->dda, player);
	run_dda(&cub->dda, cub);
	calcul_dist_wall(&ray_dist, &wall_x, cub);
	if (cub->dda.texture == EXIT)
		cub->dda.texture_x = (int)(wall_x * cub->exit_texture[0].width);
	else
		cub->dda.texture_x = (int)(wall_x
				* cub->texture[cub->dda.texture].width);
	calcul_wall(ray_dist, cub, start_x, i);
	cub->wall_dist[i] = ray_dist;
}
