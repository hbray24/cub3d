/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:21 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/19 15:19:52 by mmusquer         ###   ########.fr       */
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
		if (mode == SPRITE)
		{
			if (is_line_space(para->stock[i]))
				i++;
			else if (is_header(i, para))
				pars_header();
			else if (is_only_map_char(i, para->stock[i]) && is_header_complete(para))
				mode = MAP;
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
	if (mode != MAP)
		error_pars("Error: no map\n", para);
	if (para->map == NULL)
		error_pars("Error: no map\n", para);
}

void	parsing(char **av, t_para *para)
{
	do_gnl(para);
	check_stock(para);
}