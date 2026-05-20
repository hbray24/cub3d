/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
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
