/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:38:28 by hbray             #+#    #+#             */
/*   Updated: 2026/05/27 12:09:26 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_win(t_cub *cub)
{
	cub->player->x = 3 * 64 + 32;
	cub->player->y = 3 * 64 + 32;
	cub->player->angle = 3 * PI / 2;
	cub->texture[0].img = mlx_xpm_file_to_image(cub->mlx,
			"path_to_the_north_texture", &cub->texture[0].width,
			&cub->texture[0].height);
	cub->texture[0].data = mlx_get_data_addr(cub->texture[0].img,
			&cub->texture[0].bpp, &cub->texture[0].size_line,
			&cub->texture[0].endian);
	cub->texture[1].img = mlx_xpm_file_to_image(cub->mlx,
			"path_to_the_south_texture", &cub->texture[1].width,
			&cub->texture[1].height);
	cub->texture[1].data = mlx_get_data_addr(cub->texture[1].img,
			&cub->texture[1].bpp, &cub->texture[1].size_line,
			&cub->texture[1].endian);
	cub->texture[2].img = mlx_xpm_file_to_image(cub->mlx,
			"path_to_the_west_texture", &cub->texture[2].width,
			&cub->texture[2].height);
	cub->texture[2].data = mlx_get_data_addr(cub->texture[2].img,
			&cub->texture[2].bpp, &cub->texture[2].size_line,
			&cub->texture[2].endian);
	cub->texture[3].img = mlx_xpm_file_to_image(cub->mlx,
			"path_to_the_east_texture", &cub->texture[3].width,
			&cub->texture[3].height);
	cub->texture[3].data = mlx_get_data_addr(cub->texture[3].img,
			&cub->texture[3].bpp, &cub->texture[3].size_line,
			&cub->texture[3].endian);
}

// char	**get_map(void)
// {
// 	char	**map;

// 	map = malloc(sizeof(char *) * 10);
// 	map[0] = ft_strdup("11111111111");
// 	map[1] = ft_strdup("10000000001");
// 	map[2] = ft_strdup("10111111101");
// 	map[3] = ft_strdup("10100000101");
// 	map[4] = ft_strdup("10101110101");
// 	map[5] = ft_strdup("10100010101");
// 	map[6] = ft_strdup("10111010101");
// 	map[7] = ft_strdup("10000010001");
// 	map[8] = ft_strdup("11111111111");
// 	map[9] = NULL;
// 	return (map);
// }

void	open_win(t_cub *cub)
{
	init_win(cub);
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		write(2, "Error: MLX initialization failed\n", 34);
		close_win(cub);
	}
	mlx_get_screen_size(cub->mlx, &cub->texture->width, &cub->texture->height);
	cub->win = mlx_new_window(cub->mlx, cub->texture->width,
			cub->texture->height, "Cub3d");
	if (!cub->win)
	{
		write(2, "Error: Window creation failed\n", 31);
		close_win(cub);
	}
	cub->texture->img = mlx_new_image(cub->mlx, cub->texture->width,
			cub->texture->height);
	if (!cub->texture->img)
	{
		write(2, "Error: Image creation failed\n", 30);
		close_win(cub);
	}
	cub->texture->data = mlx_get_data_addr(cub->texture->img,
			&cub->texture->bpp, &cub->texture->size_line,
			&cub->texture->endian);
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

t_para		*create_para(void)
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