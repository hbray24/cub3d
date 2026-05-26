/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:38:28 by hbray             #+#    #+#             */
/*   Updated: 2026/05/26 11:03:44 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_player *player)
{
	player->x = 3 * 64 + 32;
	player->y = 3 * 64 + 32;
	player->angle = 3 * PI / 2;
}

char	**get_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 10);
	map[0] = ft_strdup("11111111111");
	map[1] = ft_strdup("10000000001");
	map[2] = ft_strdup("10111111101");
	map[3] = ft_strdup("10100000101");
	map[4] = ft_strdup("10101110101");
	map[5] = ft_strdup("10100010101");
	map[6] = ft_strdup("10111010101");
	map[7] = ft_strdup("10000010001");
	map[8] = ft_strdup("11111111111");
	map[9] = NULL;
	return (map);
}

void	open_win(t_cub *cub)
{
	init_player(cub->player);
	cub->map = get_map();
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		write(2, "Error: MLX initialization failed\n", 34);
		close_win(cub);
	}
	mlx_get_screen_size(cub->mlx, &cub->width, &cub->height);
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "Cub3d");
	if (!cub->win)
	{
		write(2, "Error: Window creation failed\n", 31);
		close_win(cub);
	}
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	if (!cub->img)
	{
		write(2, "Error: Image creation failed\n", 30);
		close_win(cub);
	}
	cub->data = mlx_get_data_addr(cub->img, &cub->bpp, &cub->size_line,
			&cub->endian);
}

t_cub	*create_cub(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
	{
		write(2, "Cub3d: Malloc failed\n", 22);
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
		write(2, "Cub3d: Malloc failed\n", 22);
		return (NULL);
	}
	ft_memset(player, 0, sizeof(t_player));
	return (player);
}
