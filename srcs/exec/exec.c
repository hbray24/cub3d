/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:33:40 by hbray             #+#    #+#             */
/*   Updated: 2026/05/26 17:10:17 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_player(t_player *player)
{
	if (player->rotate_left)
		player->angle -= ANGLE_SPEED;
	if (player->rotate_right)
		player->angle += ANGLE_SPEED;
}

void	translate_player(t_player *player, float cos_angle, float sin_angle)
{
	if (player->key_up)
	{
		player->x += cos_angle * SPEED;
		player->y += sin_angle * SPEED;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * SPEED;
		player->y -= sin_angle * SPEED;
	}
	if (player->key_left)
	{
		player->x += sin_angle * SPEED;
		player->y -= cos_angle * SPEED;
	}
	if (player->key_right)
	{
		player->x -= sin_angle * SPEED;
		player->y += cos_angle * SPEED;
	}
}

void	move_player(t_player *player)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	rotate_player(player);
	translate_player(player, cos_angle, sin_angle);
}

void	put_pixel(int x, int y, int color, t_cub *cub)
{
	int	index;

	if( x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return;
	index = y * cub->size_line + x * cub->bpp / 8;
	cub->data[index] = color & 0xFF;
	cub->data[index + 1] = (color >> 8) & 0xFF;
	cub->data[index + 2] = (color >> 16) & 0xFF;
}

void	clear_image(t_cub *cub)
{
	ft_memset(cub->data,0, HEIGHT * cub->size_line);
}

void	draw_square(int x, int y, int size, int color, t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < size)
		put_pixel(x + i, y, color, cub);
	i = -1;
	while (++i < size)
		put_pixel(x, y + i, color, cub);
	i = -1;
	while (++i < size)
		put_pixel(x + size, y + i, color, cub);
	i = -1;
	while (++i < size)
		put_pixel(x + i, y + size, color, cub);
}

void	draw_map(t_cub *cub)
{
	char	**map = cub->para->map;
	int		color = 0x0000FF;
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * 64, y * 64, 64, color, cub);
			x++;
		}
		y++;
	}
}

int	draw_loop(t_cub *cub)
{
	t_player 	*player;

	player = cub->player;
	move_player(player);
	clear_image(cub);
	draw_square(player->x, player->y, 10, 0x00FF00, cub);
	draw_map(cub);
	draw_direction_ray(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}
