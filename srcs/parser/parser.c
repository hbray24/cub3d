/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:21 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/20 10:30:09 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	check_stock(t_para *para)
{
	int	i;
	int	mode;

	mode = SPRITE;
	i = 0;
	while (para->stock[i])
	{
		if (mode == 10)
		{
			if (is_line_space(para->stock[i]))
			{
				i++;
				continue ;
			}
			else if (is_header(i, para) > 0)
			{
				pars_header();
				i++;
				continue ;
			}
			else if (is_only_map_char(i, para->stock[i]))
			{
				if (is_header_complete(para))
					mode = MAP;
				else
					error_pars("Error: missing header\n", para);
			}
			else
				error_pars("Error: invalid line\n", para);
		}
		if (mode == MAP)
		{
			if (is_line_space(para->stock[i]))
				error_pars("Error: empty line in map\n", para);
			else if (is_only_map_char(i, para->stock[i]))
				add_line_map(para->stock[i], para);
			else
				error_pars("Error: wrong character\n", para);
		}
		i++;
	}
	if (mode != 20)
		error_pars("Error: no map\n", para);
	if (para->map == NULL)
		error_pars("Error: no map\n", para);
}

void	parsing(char **av, t_para *para)
{
	do_gnl(para);
	check_stock(para);
}