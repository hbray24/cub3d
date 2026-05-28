/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:13:18 by hbray             #+#    #+#             */
/*   Updated: 2026/05/28 17:17:15 by mmusquer         ###   ########.fr       */
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
}

void	free_player(t_player **player)
{
	if (!player || !(*player))
		return ;
	free(*player);
}

void	free_cub(t_cub **cub)
{
	if (!cub || !(*cub))
		return ;
	if ((*cub)->texture[0].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[0].img);
	if ((*cub)->texture[1].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[1].img);
	if ((*cub)->texture[2].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[2].img);
	if ((*cub)->texture[3].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[3].img);
	if ((*cub)->col_texture[0].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[0].img);
	if ((*cub)->col_texture[1].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[1].img);
	if ((*cub)->col_texture[2].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[2].img);
	if ((*cub)->col_texture[3].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[3].img);
	if ((*cub)->col_texture[4].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[4].img);
	if ((*cub)->col_texture[5].img)
		mlx_destroy_image((*cub)->mlx, (*cub)->texture[5].img);
	if ((*cub)->player)
		free_player(&(*cub)->player);
	free(*cub);
}

void	all_free(t_para **para, t_cub **cub)
{
	free_para(para);
	free_cub(cub);
}

int	close_win(t_cub *cub)
{
	t_para	*para_tmp;
	void	*mlx_tmp;

	para_tmp = NULL;
	mlx_tmp = NULL;
	if (cub)
	{
		para_tmp = cub->para;
		mlx_tmp = cub->mlx;
	}
	if (cub && cub->screen.img)
		mlx_destroy_image(cub->mlx, cub->screen.img);
	if (cub && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	all_free(&para_tmp, &cub);
	if (mlx_tmp)
	{
		mlx_destroy_display(mlx_tmp);
		free(mlx_tmp);
	}
	exit(0);
}
