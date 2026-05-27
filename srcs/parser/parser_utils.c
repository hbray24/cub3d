/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:34 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/26 17:03:02 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_line_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	error_pars(char *msg, t_para *para)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	free_tab(para->stock);
	para->stock = NULL;
	free_tab(para->map);
	para->map = NULL;
	free(para->no_t);
	para->no_t = NULL;
	free(para->so_t);
	para->so_t = NULL;
	free(para->we_t);
	para->we_t = NULL;
	free(para->ea_t);
	para->ea_t = NULL;
	exit(1);
}
