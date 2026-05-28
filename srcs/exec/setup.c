/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:38:28 by hbray             #+#    #+#             */
/*   Updated: 2026/05/28 16:47:01 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_win(t_cub *cub)
{
	cub->texture[0].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/path_to_the_north_texture.xpm", &cub->texture[0].width,
			&cub->texture[0].height);
	cub->texture[0].data = mlx_get_data_addr(cub->texture[0].img,
			&cub->texture[0].bpp, &cub->texture[0].size_line,
			&cub->texture[0].endian);
	cub->texture[1].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/path_to_the_south_texture.xpm", &cub->texture[1].width,
			&cub->texture[1].height);
	cub->texture[1].data = mlx_get_data_addr(cub->texture[1].img,
			&cub->texture[1].bpp, &cub->texture[1].size_line,
			&cub->texture[1].endian);
	cub->texture[2].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/path_to_the_west_texture.xpm", &cub->texture[2].width,
			&cub->texture[2].height);
	cub->texture[2].data = mlx_get_data_addr(cub->texture[2].img,
			&cub->texture[2].bpp, &cub->texture[2].size_line,
			&cub->texture[2].endian);
	cub->texture[3].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/path_to_the_east_texture.xpm", &cub->texture[3].width,
			&cub->texture[3].height);
	cub->texture[3].data = mlx_get_data_addr(cub->texture[3].img,
			&cub->texture[3].bpp, &cub->texture[3].size_line,
			&cub->texture[3].endian);
	cub->texture[4].img = mlx_xpm_file_to_image(cub->mlx,
			"sprites/door_texture.xpm", &cub->texture[4].width,
			&cub->texture[4].height);
	cub->texture[4].data = mlx_get_data_addr(cub->texture[4].img,
			&cub->texture[4].bpp, &cub->texture[4].size_line,
			&cub->texture[4].endian);
}

void	open_win(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		write(2, "Error: MLX initialization failed\n", 34);
		close_win(cub);
	}
	init_win(cub);
	init_img_1(cub);
	mlx_get_screen_size(cub->mlx, &cub->screen.width, &cub->screen.height);
	cub->win = mlx_new_window(cub->mlx, cub->screen.width, cub->screen.height,
			"Cub3d");
	if (!cub->win)
	{
		write(2, "Error: Window creation failed\n", 31);
		close_win(cub);
	}
	cub->screen.img = mlx_new_image(cub->mlx, cub->screen.width,
			cub->screen.height);
	if (!cub->screen.img)
	{
		write(2, "Error: Image creation failed\n", 30);
		close_win(cub);
	}
	cub->screen.data = mlx_get_data_addr(cub->screen.img, &cub->screen.bpp,
			&cub->screen.size_line, &cub->screen.endian);
}

t_cub	*create_cub(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
	{
		write(2, "Error: Malloc failed\n", 22);
		return (NULL);
	}
	ft_memset(cub, 0, sizeof(t_cub));
	cub->player = create_player();
	if (!cub->player)
	{
		free(cub);
		return (NULL);
	}
	return (cub);
}

t_player	*create_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		write(2, "Error: Malloc failed\n", 22);
		return (NULL);
	}
	ft_memset(player, 0, sizeof(t_player));
	return (player);
}

t_para	*create_para(void)
{
	t_para	*para;

	para = malloc(sizeof(t_para));
	if (!para)
	{
		write(2, "Error: Malloc failed\n", 22);
		return (NULL);
	}
	ft_memset(para, 0, sizeof(t_para));
	return (para);
}
