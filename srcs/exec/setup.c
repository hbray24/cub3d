/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:38:28 by hbray             #+#    #+#             */
/*   Updated: 2026/05/21 16:39:35 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) b;
	while (len > 0)
	{
		*tmp = (unsigned char) c;
		tmp++;
		len--;
	}
	return (b);
}

void	init_player(t_player *player)
{
	player->x = 3 * 64 + 32;
	player->y = 3 * 64 + 32;
	player->angle = PI / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->rotate_left = false;
	player->rotate_right = false;
}

char **get_map(void)
{
	char	**map;

	map= malloc(sizeof(char *) *11);
	map[0] = "1111111111";
	map[1] = "1000000001";
	map[2] = "1000001111";
	map[3] = "1000000001";
	map[4] = "1000100001";
	map[5] = "1000000001";
	map[6] = "1000000001";
	map[7] = "1000001001";
	map[8] = "1000001001";
	map[9] = "1111111111";
	map[10] = NULL;
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
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!cub->win)
	{
		write(2, "Error: Window creation failed\n", 31);
		close_win(cub);
	}
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->img)
	{
		write(2, "Error: Image creation failed\n", 30);
		close_win(cub);
	}
	cub->data = mlx_get_data_addr(cub->img, &cub->bpp, &cub->size_line,
			&cub->endian);
}

t_cub *create_cub(void)
{
	t_cub *cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
	{
		write(2, "Cub3d: Malloc failed\n", 22);
		return (NULL);
	}
	ft_memset(cub, 0, sizeof(t_cub));
	cub->player = create_player();
	if(!cub->player)
	{
		free(cub);
		return (NULL);
	}
	return (cub);
}

t_player *create_player(void)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		write(2, "Cub3d: Malloc failed\n", 22);
		return (NULL);
	}
	ft_memset(player, 0, sizeof(t_player));
	return (player);
}
