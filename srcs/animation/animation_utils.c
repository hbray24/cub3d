/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:26:30 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/29 10:27:11 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_time(void)
{
	struct timeval	tv;
	double			time;

	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec)) + ((tv.tv_usec) / 1000000.0);
	return (time);
}