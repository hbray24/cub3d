/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:13:18 by hbray             #+#    #+#             */
/*   Updated: 2026/05/27 16:46:51 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_para(t_para **para)
{
	if (!para || !(*para))
		return ;
	free_tab((*para)->stock);
	(*para)->stock = NULL;
	free_tab((*para)->map);
	(*para)->map = NULL;
	free((*para)->no_t);
	(*para)->no_t = NULL;
	free((*para)->so_t);
	(*para)->so_t = NULL;
	free((*para)->we_t);
	(*para)->we_t = NULL;
	free((*para)->ea_t);
	(*para)->ea_t = NULL;
	free(*para);
	*para = NULL;
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
	free(*cub);
	*cub = NULL;
}

void	all_free(t_para **para)
{
	if (!para || !*para)
		return ;
	if ((*para)->cub->player)
		free_player(&(*para)->cub->player);
	if ((*para)->cub)
		free_cub(&(*para)->cub);
	free_para(para);
}

int	close_win(t_cub *cub)
{
	if (cub->screen.img)
		mlx_destroy_image(cub->mlx, cub->screen.img);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	all_free(&cub->para);
	exit(0);
}
