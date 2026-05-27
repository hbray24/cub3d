/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validation_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:44:52 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/26 16:45:12 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_player(char c)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (1);
    return (0);
}

float   convert_angle(char c)
{
    float i;

    i = 0;
    if (c == 'N')
        i = 3 * PI / 2;
    if (c == 'S')
        i = PI / 2;
    if (c == 'W')
        i = PI;
    if (c == 'E')
        i = PI * 2;
    return (i);
}