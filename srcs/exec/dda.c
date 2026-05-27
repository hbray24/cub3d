/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:01:08 by hbray             #+#    #+#             */
/*   Updated: 2026/05/27 11:34:04 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_dda_step(float start_x, t_dda *dda, t_player *player)
{
	ft_memset(dda, 0, sizeof(t_dda));
	dda->angle_x = cos(start_x);
	dda->angle_y = sin(start_x);
	dda->pos_x = player->x / 64;
	dda->pos_y = player->y / 64;
	dda->map_x = (int)dda->pos_x;
	dda->map_y = (int)dda->pos_y;
	dda->delta_dist_x = fabs(1 / dda->angle_x);
	dda->delta_dist_y = fabs(1 / dda->angle_y);
	if (dda->angle_x < 0)
		dda->step_x = -1;
	else
		dda->step_x = 1;
	if (dda->angle_y < 0)
		dda->step_y = -1;
	else
		dda->step_y = 1;
	if (dda->angle_x < 0)
		dda->side_dist_x = (dda->pos_x - dda->map_x) * dda->delta_dist_x;
	else
		dda->side_dist_x = (dda->map_x + 1.0 - dda->pos_x) * dda->delta_dist_x;
	if (dda->angle_y < 0)
		dda->side_dist_y = (dda->pos_y - dda->map_y) * dda->delta_dist_y;
	else
		dda->side_dist_y = (dda->map_y + 1.0 - dda->pos_y) * dda->delta_dist_y;
}

void	run_dda(t_dda *dda, t_cub *cub)
{
	int	touch;

	touch = 0;
	while (touch == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (dda->map_x < 0 || dda->map_x >= 10 || dda->map_y < 0
			|| dda->map_y >= 10)
			break ;
		if (cub->para->map[dda->map_y][dda->map_x] == '1')
			touch = 1;
	}
}

void	draw_direction_ray(t_cub *cub)
{
	float	dir_x;
	float	dir_y;
	int		length;
	int		i;

	dir_x = cos(cub->player->angle);
	dir_y = sin(cub->player->angle);
	length = 30;
	i = 0;
	while (i < length)
	{
		put_pixel((int)cub->player->x, (int)cub->player->y, 0xFF0000, cub);
		cub->player->x += dir_x;
		cub->player->y += dir_y;
		i++;
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
	cub->dda.wall_height = (64 / dist) * (cub->screen.width / 2);
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
	if (cub->dda.side == 0)
	{
		ray_dist = cub->dda.side_dist_x - cub->dda.delta_dist_x;
		wall_x = cub->dda.pos_y + ray_dist * cub->dda.angle_y;
		if (cub->dda.step_x > 0)
			cub->dda.texture = WEST;
		else
			cub->dda.texture = EAST;
	}
	else
	{
		ray_dist = cub->dda.side_dist_y - cub->dda.delta_dist_y;
		wall_x = cub->dda.pos_x + ray_dist * cub->dda.angle_x;
		if (cub->dda.step_y > 0)
			cub->dda.texture = NORTH;
		else
			cub->dda.texture = SOUTH;
	}
	wall_x -= floor(wall_x);
	cub->dda.texture_x = (int)(wall_x * 64);
	calcul_wall(ray_dist, cub, start_x, i);
}
