/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:34 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/27 16:29:19 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_line_space(char *str)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]))
			j++;
		i++;
	}
	if (i == j)
		return (1);
	return (0);
}

void	error_pars(char *msg, t_para *para)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	all_free(&para);
	exit(1);
}
