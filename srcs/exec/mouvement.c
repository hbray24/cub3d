/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:51:54 by hbray             #+#    #+#             */
/*   Updated: 2026/05/28 14:41:42 by hbray            ###   ########.fr       */
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
	return (0);
}

void	rotate_player(t_player *player)
{
	if (player->rotate_left)
		player->angle -= ANGLE_SPEED;
	if (player->rotate_right)
		player->angle += ANGLE_SPEED;
}

void	move_x(t_cub *cub, t_player *player, float cos_angle, float sin_angle)
{
	float	next_x;
	float	next_y;

	if (player->key_left)
	{
		next_x = player->x + sin_angle * SPEED;
		next_y = player->y - cos_angle * SPEED;
		if (!wall(cub, next_x, player->y))
			player->x = next_x;
		if (!wall(cub, player->x, next_y))
			player->y = next_y;
	}
	if (player->key_right)
	{
		next_x = player->x - sin_angle * SPEED;
		next_y = player->y + cos_angle * SPEED;
		if (!wall(cub, next_x, player->y))
			player->x = next_x;
		if (!wall(cub, player->x, next_y))
			player->y = next_y;
	}
}

void	move_y(t_cub *cub, t_player *player, float cos_angle, float sin_angle)
{
	float	next_x;
	float	next_y;

	if (player->key_up)
	{
		next_x = player->x + cos_angle * SPEED;
		next_y = player->y + sin_angle * SPEED;
		if (!wall(cub, next_x, player->y))
			player->x = next_x;
		if (!wall(cub, player->x, next_y))
			player->y = next_y;
	}
	if (player->key_down)
	{
		next_x = player->x - cos_angle * SPEED;
		next_y = player->y - sin_angle * SPEED;
		if (!wall(cub, next_x, player->y))
			player->x = next_x;
		if (!wall(cub, player->x, next_y))
			player->y = next_y;
	}
}

void	move_player(t_cub *cub)
{
	t_player	*player;
	float		cos_angle;
	float		sin_angle;

	player = cub->player;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	rotate_player(player);
	move_x(cub, player, cos_angle, sin_angle);
	move_y(cub, player, cos_angle, sin_angle);
}
