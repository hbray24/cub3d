/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:53:28 by hbray             #+#    #+#             */
/*   Updated: 2026/06/02 15:29:21 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_square(t_pos pos, int size, int color, t_cub *cub)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i < size)
	{
		a = 0;
		while (a < size)
		{
			put_pixel(pos.x + a, pos.y + i, color, cub);
			a++;
		}
		i++;
	}
}

void	draw_direction_ray(t_cub *cub)
{
	float	dir_x;
	float	dir_y;
	float	tmp_x;
	float	tmp_y;
	int		i;

	dir_x = cos(cub->player->angle);
	dir_y = sin(cub->player->angle);
	tmp_x = cub->player->x;
	tmp_y = cub->player->y;
	i = 0;
	while (i < LENGTH)
	{
		put_pixel((int)(tmp_x / 4), (int)(tmp_y / 4), 0xFF0000, cub);
		tmp_x += dir_x;
		tmp_y += dir_y;
		i++;
	}
}

void	draw_minimap(t_cub *cub)
{
	int		y;
	int		x;

	y = -1;
	while (cub->para->map[++y])
	{
		x = -1;
		while (cub->para->map[y][++x])
		{
			if (cub->para->map[y][x] == '1')
				draw_square((t_pos){x * 16, y * 16}, 16, 0x0000FF, cub);
			if (cub->para->map[y][x] == '0')
				draw_square((t_pos){x * 16, y * 16}, 16, 0xFFFFFF, cub);
			if (cub->para->map[y][x] == 'D')
				draw_square((t_pos){x * 16, y * 16}, 16, 0xFFFF00, cub);
			if (cub->para->map[y][x] == 'R')
				draw_square((t_pos){x * 16, y * 16}, 16, 0x00FF00, cub);
			if (cub->para->map[y][x] == 'X')
				draw_square((t_pos){x * 16, y * 16}, 16, 0xFF0000, cub);
		}
	}
	draw_square((t_pos){(cub->player->x / 4) - 4, (cub->player->y / 4) - 4}, 8,
		0xFF0000, cub);
	draw_direction_ray(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.img, 0, 0);
}
