/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:51:54 by hbray             #+#    #+#             */
/*   Updated: 2026/06/02 09:53:32 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	wall(t_cub *cub, float x, float y)
{
	int	marge;

	marge = 16;
	if (cub->para->map[(int)(y - (marge / 2)) / 64][(int)(x - (marge / 2))
		/ 64] == '1' || cub->para->map[(int)(y - (marge / 2)) / 64][(int)(x
			+ (marge / 2)) / 64] == '1' || cub->para->map[(int)(y + (marge / 2))
		/ 64][(int)(x - (marge / 2)) / 64] == '1' || cub->para->map[(int)(y
			+ (marge / 2)) / 64][(int)(x + (marge / 2)) / 64] == '1')
		return (1);
	if (cub->para->map[(int)(y - (marge / 2)) / 64][(int)(x - (marge / 2))
		/ 64] == 'X' || cub->para->map[(int)(y - (marge / 2)) / 64][(int)(x
			+ (marge / 2)) / 64] == 'X' || cub->para->map[(int)(y + (marge / 2))
		/ 64][(int)(x - (marge / 2)) / 64] == 'X' || cub->para->map[(int)(y
			+ (marge / 2)) / 64][(int)(x + (marge / 2)) / 64] == 'X')
		return (1);
	if ((cub->para->map[(int)(y - (marge / 2)) / 64][(int)(x - (marge / 2))
		/ 64] == 'D' || cub->para->map[(int)(y - (marge / 2)) / 64][(int)(x
		+ (marge / 2)) / 64] == 'D' || cub->para->map[(int)(y + (marge / 2))
		/ 64][(int)(x - (marge / 2)) / 64] == 'D' || cub->para->map[(int)(y
		+ (marge / 2)) / 64][(int)(x + (marge / 2)) / 64] == 'D')
		&& get_door_lvl(cub, (int)(x / 64), (int)(y / 64)) < 0.8)
		return (1);
	return (0);
}

void	rotate_player(t_player *player, double frametime)
{
	if (player->rotate_left)
		player->angle -= (ANGLE_SPEED * frametime);
	if (player->rotate_right)
		player->angle += (ANGLE_SPEED * frametime);
}

void	move_x(t_cub *cub, float cos_angle, float sin_angle, double frametime)
{
	t_player	*player;
	float		next_x;
	float		next_y;
	double		speed;

	player = cub->player;
	speed = SPEED * frametime;
	if (player->key_left)
	{
		next_x = player->x + sin_angle * speed;
		next_y = player->y - cos_angle * speed;
		if (!wall(cub, next_x, player->y))
			player->x = next_x;
		if (!wall(cub, player->x, next_y))
			player->y = next_y;
	}
	if (player->key_right)
	{
		next_x = player->x - sin_angle * speed;
		next_y = player->y + cos_angle * speed;
		if (!wall(cub, next_x, player->y))
			player->x = next_x;
		if (!wall(cub, player->x, next_y))
			player->y = next_y;
	}
}

void	move_y(t_cub *cub, float cos_angle, float sin_angle, double frametime)
{
	t_player	*player;
	float		next_x;
	float		next_y;
	double		speed;

	player = cub->player;
	speed = SPEED * frametime;
	if (player->key_up)
	{
		next_x = player->x + cos_angle * speed;
		next_y = player->y + sin_angle * speed;
		if (!wall(cub, next_x, player->y))
			player->x = next_x;
		if (!wall(cub, player->x, next_y))
			player->y = next_y;
	}
	if (player->key_down)
	{
		next_x = player->x - cos_angle * speed;
		next_y = player->y - sin_angle * speed;
		if (!wall(cub, next_x, player->y))
			player->x = next_x;
		if (!wall(cub, player->x, next_y))
			player->y = next_y;
	}
}

void	move_player(t_cub *cub, double frametime)
{
	t_player	*player;
	float		cos_angle;
	float		sin_angle;

	player = cub->player;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	rotate_player(player, frametime);
	move_x(cub, cos_angle, sin_angle, frametime);
	move_y(cub, cos_angle, sin_angle, frametime);
}
