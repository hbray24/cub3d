/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:21:06 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/27 18:03:30 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	player_info(int i, int j, t_para *para)
{
	para->cub->player->y = i;
	para->cub->player->x = j;
	para->cub->player->angle = convert_angle(para->map[i][j]);
	para->map[i][j] = '0';
	para->nb_player++;
}

static int	is_border(char **map, int y, int x)
{
	if (y == 0 || x == 0)
		return (1);
	if (y == count_line(map) - 1)
		return (1);
	if ((size_t)(x + 1) >= ft_strlen(map[y]) || (size_t)x >= ft_strlen(map[y - 1])
		|| (size_t)x >= ft_strlen(map[y + 1]))
		return (1);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x - 1] == ' '
		|| map[y][x + 1] == ' ')
		return (1);
	return (0);
}

static void	find_info(t_para *para)
{
	int	i;
	int	j;

	i = 0;
	while (para->map[i])
	{
		j = 0;
		while (para->map[i][j])
		{
			if (is_player(para->map[i][j]))
				player_info(i, j, para);
			else if (para->map[i][j] == 'R')
				para->nb_collec++;
			else if (para->map[i][j] == 'X')
			{
				if (!is_border(para->map, j, i))
					error_pars("Error: exit must be on border", para);
				para->nb_exit++;
			}
			j++;
		}
		i++;
	}
	if (para->nb_player != 1)
		error_pars("Error: wrong number of player\n", para);
	if (para->nb_exit > 1)
		error_pars("Error: too many exit\n", para);
}

void	map_validation(t_para *para)
{
	find_info(para);
	flood_fill(para);
}
