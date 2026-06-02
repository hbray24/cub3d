/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:33:40 by hbray             #+#    #+#             */
/*   Updated: 2026/06/01 16:28:38 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clear_image(t_cub *cub)
{
	ft_memset(cub->screen.data, 0, cub->screen.height * cub->screen.size_line);
}

float	update_and_render(t_cub *cub)
{
	double	frametime;

	cub->old_time = cub->time;
	cub->time = get_time();
	frametime = cub->time - cub->old_time;
	if (frametime > 0.05 || frametime < 0.0)
		frametime = 0.05;
	return (frametime);
}



int	draw_loop(t_cub *cub)
{
	t_player	*player;
	float		fraction;
	float		start_x;
	double		frametime;
	int			i;
	int			j;

	frametime = update_and_render(cub);
	i = 0;
	player = cub->player;
	move_player(cub, frametime);
	clear_image(cub);
	fraction = PI / 3 / cub->screen.width;
	start_x = player->angle - PI / 6;
	while (i < cub->screen.width)
	{
		draw_line(player, cub, start_x, i);
		start_x += fraction;
		i++;
	}
	j = 0;
	while (j < cub->para->nb_collec)
	{
		if (!cub->col[j].collect)
		{
			anim_maj(&cub->col[j].anim, get_time());
			draw_collectible(cub, &cub->col[j]);
		}
		j++;
	}
	draw_minimap(cub);
	render_hud(cub);
	anim_maj(&cub->hud_anim, get_time());
	anim_maj(&cub->exit_anim, get_time());
	uptade_doors(cub, frametime);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.img, 0, 0);
	return (0);
}
