/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:34 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/27 16:33:29 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_line_space(char *str)
{
	int	i;

	i = 0;
	while (!ft_is_space(str[i]))
			i++;
	if (str[i] == '\0')
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
