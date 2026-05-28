/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:53:28 by hbray             #+#    #+#             */
/*   Updated: 2026/05/28 16:32:25 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_square(int x, int y, int size, int color, t_cub *cub)
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
			put_pixel(x + a, y + i, color, cub);
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
	char	**map;
	int		y;
	int		x;

	map = cub->para->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				draw_square(x * 16, y * 16, 16, 0x0000FF, cub);
			}
			if (map[y][x] == '0')
				draw_square(x * 16, y * 16, 16, 0xFFFFFF, cub);
			if (map[y][x] == 'D')
				draw_square(x * 16, y * 16, 16, 0xFFFF00, cub); 
			x++;
		}
		y++;
	}
	draw_square((cub->player->x / 4) - 4, (cub->player->y / 4) - 4, 8, 0xFF0000, cub);
	draw_direction_ray(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.img, 0, 0);
}
