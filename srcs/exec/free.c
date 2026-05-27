/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:13:18 by hbray             #+#    #+#             */
/*   Updated: 2026/05/27 11:28:12 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_map(char **str)
{
	int	i;

	i = 0;
	if (!str || !(*str))
		return ;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
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
	free_map((*cub)->para->map);
	free(*cub);
	*cub = NULL;
}

void	all_free(t_cub **cub, t_player **player)
{
	free_player(player);
	free_cub(cub);
}

int	close_win(t_cub *cub)
{
	if (cub->texture->img)
		mlx_destroy_image(cub->mlx, cub->texture->img);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	all_free(&cub, &cub->player);
	exit(0);
}
