/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:33:40 by hbray             #+#    #+#             */
/*   Updated: 2026/05/26 11:03:36 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(int x, int y, int color, t_cub *cub)
{
	char	*dst;

	if (x > 0 && y > 0 && cub->width > x && cub->height > y)
	{
		dst = cub->data + (y * cub->size_line + x * (cub->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	clear_image(t_cub *cub)
{
	ft_memset(cub->data, 0, cub->height * cub->size_line);
}

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

void	draw_map(t_cub *cub)
{
	char	**map;
	int		y;
	int		x;

	map = cub->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				draw_square(x * 64, y * 64, 64, 0x0000FF, cub);
			}
			if (map[y][x] == '0')
				draw_square(x * 64, y * 64, 64, 0xFFFFFF, cub);
			x++;
		}
		y++;
	}
}

int	draw_loop(t_cub *cub)
{
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

	i = 0;
	player = cub->player;
	move_player(cub);
	clear_image(cub);
	fraction = PI / 3 / cub->width;
	start_x = player->angle - PI / 6;
	while (i < cub->width)
	{
		draw_line(player, cub, start_x, i);
		start_x += fraction;
		i++;
	}
	// draw_map(cub);
	// draw_square(player->x - 5, player->y - 5, 10, 0x00FF00, cub);
	// draw_direction_ray(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}
