/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:58:29 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/19 10:53:03 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	setup(int ac, char **av, t_para *para)
{
	int		fd;
	int		i;
	
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
	ft_memset(para, 0, sizeof(t_para));
	para->floor_c = -1;
	para->ceiling_c = -1;
	return (fd);
}

int	main(int ac, char **av)
{
	t_para	para;
	
	setup(ac, av, &para);
	parsing(av, &para);
}
=======
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:47:06 by hbray             #+#    #+#             */
/*   Updated: 2026/05/20 15:26:22 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(void)
{
	t_cub	*cub;

	cub = create_cub();
	if (!cub)
		return (1);
	open_win(cub);
	mlx_hook(cub->win, 17, 0, (int (*)(void))(void *)close_win, cub);
	mlx_hook(cub->win, 2, 1L << 0, (int (*)(void))(void *)key_press, cub->player);
	mlx_hook(cub->win, 3, 1L << 1, (int (*)(void))(void *)key_release, cub->player);
	mlx_loop_hook(cub->mlx, (int (*)(void))(void *)draw_loop, cub);
	mlx_loop(cub->mlx);
	return (0);
}
>>>>>>> origin/main
