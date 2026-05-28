/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:18:53 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/28 17:38:04 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_col(int i, int x, int y, t_col *col)
{
	int j;

	j = 0;
	col[i].x = x;
	col[i].y = y;
	col[i].anim.current_frame = 0;
	col[i].anim.frame_count = 6;
	ft_memset(col[i].anim.frame, 0, sizeof(int) * 6);
	while (j < col[i].anim.frame_count)
	{
		col[i].anim.frame[j] = j;
		j++;
	}
	col[i].anim.last_frame = get_time();
	col[i].anim.time_b_frame = ANIM_SPEED;
}

t_col	*create_col(t_cub *cub)
{
	t_col	*col;
	int	i;
	int y;
	int x;

	i = 0;
	y = 0;
	col = malloc(sizeof(t_col) * cub->para->nb_collec);
	if (!col)
		error_pars("Error: malloc failed\n", cub->para);
	while (cub->para->map[y])
	{
		x = 0;
		while (cub->para->map[y][x])
		{
			if (cub->para->map[y][x] == 'R')
			{
				init_col(i, x, y, col);
				i++;
			}
			x++;
		}
		y++;
	}
	return (col);
}
