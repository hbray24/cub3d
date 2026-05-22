/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:18:44 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/21 17:02:36 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    malloc_map(char **line, int i, t_para *para)
{
    int n;

    n = 0;
    while(line[i])
    {
        i++;
        n++;
    }    
    para->cub->map = ft_calloc(n + 1, sizeof(char *));
    if (!para->cub->map)
        error_pars("Error: malloc failed\n", para);
}

void add_line_map(char *line, t_para *para)
{
    
}