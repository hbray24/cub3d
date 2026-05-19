/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:34 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/19 15:00:26 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_line_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]))
			return (0);
	}
	return (1);
}

void	error_pars(char *msg, t_para *para)
{
	
}