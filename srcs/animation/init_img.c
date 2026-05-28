/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:07:40 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/28 17:25:56 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_img_2(t_cub *cub)
{
	cub->col_texture[4].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_5.xpm", &cub->col_texture[0].width,
			&cub->col_texture[4].height);
	cub->col_texture[4].data = mlx_get_data_addr(cub->col_texture[0].img,
			&cub->col_texture[4].bpp, &cub->col_texture[0].size_line,
			&cub->col_texture[4].endian);
	cub->col_texture[5].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_6.xpm", &cub->col_texture[0].width,
			&cub->col_texture[5].height);
	cub->col_texture[5].data = mlx_get_data_addr(cub->col_texture[0].img,
			&cub->col_texture[5].bpp, &cub->col_texture[0].size_line,
			&cub->col_texture[5].endian);
}

void	init_img_1(t_cub *cub)
{
	cub->col_texture[0].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_1.xpm", &cub->col_texture[0].width,
			&cub->col_texture[0].height);
	cub->col_texture[0].data = mlx_get_data_addr(cub->col_texture[0].img,
			&cub->col_texture[0].bpp, &cub->col_texture[0].size_line,
			&cub->col_texture[0].endian);
	cub->col_texture[1].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_2.xpm", &cub->col_texture[0].width,
			&cub->col_texture[1].height);
	cub->col_texture[1].data = mlx_get_data_addr(cub->col_texture[0].img,
			&cub->col_texture[1].bpp, &cub->col_texture[0].size_line,
			&cub->col_texture[1].endian);
	cub->col_texture[2].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_3.xpm", &cub->col_texture[0].width,
			&cub->col_texture[2].height);
	cub->col_texture[2].data = mlx_get_data_addr(cub->col_texture[0].img,
			&cub->col_texture[2].bpp, &cub->col_texture[0].size_line,
			&cub->col_texture[2].endian);
	cub->col_texture[3].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/collectible_frame_4.xpm", &cub->col_texture[0].width,
			&cub->col_texture[3].height);
	cub->col_texture[3].data = mlx_get_data_addr(cub->col_texture[0].img,
			&cub->col_texture[3].bpp, &cub->col_texture[0].size_line,
			&cub->col_texture[3].endian);
	init_img_2(cub);
}
