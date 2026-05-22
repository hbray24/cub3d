/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:13:18 by hbray             #+#    #+#             */
/*   Updated: 2026/05/21 16:39:50 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_win(t_cub *cub)
{
	if (!cub->img)
		mlx_destroy_image(cub->mlx, cub->img);
	if(!cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (!cub->mlx)
		mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	exit(0);
}

void	free_map(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str && str[++i])
		free(str[i]);
	free(str);
}

void	free_player(t_player **player)
{
	if (!player || !(*player))
		return ;
	free(*player);
	*player = NULL;
}

void	free_cub(t_cub **cub)
{
	if (!cub || !(*cub))
		return ;
	free_map((*cub)->map);
	free(*cub);
	*cub = NULL;
}

void	all_free(t_cub **cub, t_player **player)
{
	free_player(player);
	free_cub(cub);
}
