/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:11:12 by hbray             #+#    #+#             */
/*   Updated: 2026/06/02 15:50:39 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_door_lvl(t_cub *cub, int x, int y)
{
	int	i;

	i = 0;
	while (i < cub->para->nb_door)
	{
		if (cub->door[i].x == x && cub->door[i].y == y)
			return (cub->door[i].open_lvl);
		i++;
	}
	return (0);
}

void	door_open(t_cub *cub, t_pos pos, double frametime, int i)
{
	if (cub->door[i].state == OPENING)
	{
		cub->door[i].open_lvl += (1.5 * frametime);
		if (cub->door[i].open_lvl >= 1.0)
		{
			cub->door[i].open_lvl = 1.0;
			cub->door[i].state = OPEN;
			cub->door[i].timer = 0.0;
		}
	}
	else if (cub->door[i].state == OPEN)
	{
		cub->door[i].timer += frametime;
		if (cub->door[i].timer > 3.0 && !(pos.x == cub->door[i].x
				&& pos.y == cub->door[i].y))
			cub->door[i].state = CLOSING;
	}
}

void	update_doors(t_cub *cub, double frametime)
{
	int	i;
	int	p_x;
	int	p_y;

	i = 0;
	p_x = (int)(cub->player->x / 64);
	p_y = (int)(cub->player->y / 64);
	while (i < cub->para->nb_door)
	{
		if (cub->door[i].state == OPEN || cub->door[i].state == OPENING)
			door_open(cub, (t_pos){p_x, p_y}, frametime, i);
		else if (cub->door[i].state == CLOSING)
		{
			cub->door[i].open_lvl -= (1.5 * frametime);
			if (cub->door[i].open_lvl <= CLOSE)
			{
				cub->door[i].open_lvl = CLOSE;
				cub->door[i].state = 0;
			}
		}
		i++;
	}
}

void	open_door(t_cub *cub)
{
	int	target_x;
	int	target_y;
	int	i;

	target_x = (cub->player->x + cos(cub->player->angle) * 64) / 64;
	target_y = (cub->player->y + sin(cub->player->angle) * 64) / 64;
	if (cub->para->map[target_y][target_x] == 'D')
	{
		i = 0;
		while (i < cub->para->nb_door)
		{
			if (cub->door[i].x == target_x && cub->door[i].y == target_y)
			{
				if (cub->door[i].state == CLOSE
					|| cub->door[i].state == CLOSING)
					cub->door[i].state = OPENING;
			}
			i++;
		}
	}
}
