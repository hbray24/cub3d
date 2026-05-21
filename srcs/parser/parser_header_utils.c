/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:00:15 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/20 17:31:24 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pars_texture_cut(char *line, char *tmp, int i, t_para *para)
{
	int fd;
	
	while (line[i])
	{
		if (!ft_is_space(line[i]))
		{
			free(tmp);
			error_pars("Error: invalid content\n", para);
		}
		i++;
	}
	fd = open(tmp, O_RDONLY);
	if (fd < 0)
	{
		free(tmp);
		error_pars("Error: invalid file\n", para);
	}
	close(fd);
}


static int count_comma(char *str, char c)
{
	
}

void	color_split(char *line, char *tmp, int i, t_para *para)
{
	char	**tab;
	int i;
	
	i = 0;
	tab = ft_split(tmp, ",");
}