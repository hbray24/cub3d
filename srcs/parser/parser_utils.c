/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:34 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/21 11:56:46 by hbray            ###   ########.fr       */
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
		i++;
	}
	return (1);
}

void	error_pars(char *msg, t_para *para)
{
	
}