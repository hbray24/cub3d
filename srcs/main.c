/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:58:29 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/04 10:08:25 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	setup(int ac, char **av, t_para *para)
{
	int	i;

	para->floor_c = -1;
	para->ceiling_c = -1;
	if (ac != 2)
		error_pars("Error: too many arguments\n", para);
	para->path = av[1];
	i = ft_strlen(para->path);
	if (i < 5)
		error_pars("Usage: path/name_map.cub\n", para);
	if (ft_strncmp(para->path + i - 4, ".cub", 4) != 0)
		error_pars("Usage: path/name_map.cub\n", para);
	if (para->path[i - 5] == '/')
		error_pars("Usage: path/name_map.cub\n", para);
}

int	mouse_handler(int x, int y, t_cub *cub)
{
	int	delta_x;
	int	center_x;
	int	center_y;

	if (cub->mouse_locked == 0)
		return (0);
	(void)y;
	center_x = cub->screen.width / 2;
	center_y = cub->screen.height / 2;
	if (x == center_x)
		return (0);
	delta_x = x - center_x;
	cub->player->angle += delta_x * 0.0002;
	mlx_mouse_move(cub->mlx, cub->win, center_x, center_y);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	*cub;
	t_para	*para;

	cub = create_cub();
	cub->time = get_time();
	para = create_para();
	if (!cub || !para)
		return (all_free(&para, &cub), 1);
	para->cub = cub;
	cub->para = para;
	setup(ac, av, para);
	parsing(para);
	if (init_doors(cub, para))
		return (all_free(&para, &cub), 1);
	open_win(cub);
	pixar(cub);
	mlx_hook(cub->win, 17, 0, (int (*)(void))(void *)close_win, cub);
	mlx_hook(cub->win, 2, 1L << 0, (int (*)(void))(void *)key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, (int (*)(void))(void *)key_release,
		cub->player);
	mlx_hook(cub->win, 6, 1L << 6, (int (*)(void))(void *)mouse_handler, cub);
	mlx_loop_hook(cub->mlx, (int (*)(void))(void *)draw_loop, cub);
	mlx_loop(cub->mlx);
	all_free(&para, &cub);
	return (0);
}
