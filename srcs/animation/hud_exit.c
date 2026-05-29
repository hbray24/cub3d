/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:45:50 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/29 18:00:48 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_hud(t_cub *cub)
{
	float	start_x;
	float	start_y;
	int		color;
	int		y;
	int		x;

	start_x = cub->screen.width / 2 - cub->hud_texture->width / 2;
	start_y = cub->screen.height - cub->hud_texture->height;
	y = 0;
	while (y < cub->hud_texture->height)
	{
		x = 0;
		while (x < cub->hud_texture->width)
		{
			color = get_color(&cub->hud_texture[cub->hud_anim.current_frame], x,
					y);
			if (color != 0 && color != -16777216)
				put_pixel(start_x + x, start_y + y, color, cub);
			x++;
		}
		y++;
	}
}