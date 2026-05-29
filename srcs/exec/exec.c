/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:33:40 by hbray             #+#    #+#             */
/*   Updated: 2026/05/29 16:09:16 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(int x, int y, int color, t_cub *cub)
{
	char	*dst;

	if (x > 0 && y > 0 && cub->screen.width > x && cub->screen.height > y)
	{
		dst = cub->screen.data + (y * cub->screen.size_line + x
				* (cub->screen.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

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
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.img, 0, 0);
	return (0);
}
