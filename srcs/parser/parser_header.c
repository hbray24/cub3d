/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:05:30 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/20 17:09:19 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pars_header(char *line, t_para *para)
{
	if (para->header == NO)
		pars_texture(line, &para->no_t, para);
	if (para->header == SO)
		pars_texture(line, &para->so_t, para);
	if (para->header == WE)
		pars_texture(line, &para->we_t, para);
	if (para->header == EA)
		pars_texture(line, &para->ea_t, para);
	if (para->header == F)
		pars_color(line, &para->floor_c, para);
	if (para->header == F)
		pars_color(line, &para->ceiling_c, para);
}

static void	pars_texture(char *line, char **path, t_para *para)
{
	int i;
	int j;
	char *tmp;
	
	i = 0;
	if (*path != NULL)
		error_pars("Error: duplicate identifier\n", para);
	while (line[i] && ft_is_space(line[i]))
		i++;
	i += 2;
	while (line[i] && ft_is_space(line[i]))
			i++;
	if (line[i] == '\0')
		error_pars("Error: empty path\n", para);
	j = i;
	while (line[i] && !ft_is_space(line[i]))
		i++;
	tmp = ft_substr(line, j, i - j);
	if (!tmp)
		error_pars("Error: malloc fail\n", para);
	pars_texture_cut(line, tmp, i, para);
	*path = tmp;
}



static void	pars_color(char *line, char **color, t_para *para)
{
	int i;
	int j;
	char *tmp;
	
	i = 0;
	if (*color != NULL)
		error_pars("Error: duplicate identifier\n", para);
	while (line[i] && ft_is_space(line[i]))
		i++;
	i += 2;
	while (line[i] && ft_is_space(line[i]))
			i++;
	if (line[i] == '\0')
		error_pars("Error: empty path\n", para);
	j = i;
	while (line[i] && !ft_is_space(line[i]))
		i++;
	tmp = ft_substr(line, j, i - j);
	if (!tmp)
		error_pars("Error: malloc fail\n", para);
	while (line[i])
	{
		if (!ft_is_space(line[i]))
		{
			free(tmp);
			error_pars("Error: invalid content\n", para);
		}
		i++;
	}
	*color = tmp;
}
