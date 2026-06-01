/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:22:27 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/01 10:36:27 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	render_collectible_y(float texture_x, int x, t_cub *cub, t_col *col)
{
	float	texture_y;
	float	start_y;
	float	end_y;
	int		color;
	int		y;

	start_y = cub->screen.height * 0.6 + col->bob;
	end_y = start_y + col->sprite_height;
	y = start_y;
	while (y < end_y)
	{
		texture_y = (y - start_y) / col->sprite_height
			* cub->col_texture[0].height;
		color = get_color(&cub->col_texture[col->anim.current_frame], texture_x,
				texture_y);
		if (color != 0 && color != -16777216)
			put_pixel(x, y, color, cub);
		y++;
	}
}

static void	render_collectible_x(t_cub *cub, t_col *col)
{
	float	start_x;
	float	end_x;
	float	texture_x;
	int		x;

	start_x = col->sprite_screen_x - (col->sprite_height / 2);
	end_x = col->sprite_screen_x + (col->sprite_height / 2);
	x = start_x;
	while (x < end_x)
	{
		if (x < 0 || x >= cub->screen.width)
		{
			x++;
			continue ;
		}
		if (col->dist / 64 > cub->wall_dist[x])
		{
			x++;
			continue ;
		}
		texture_x = (x - start_x) / col->sprite_height
			* cub->col_texture[0].width;
		render_collectible_y(texture_x, x, cub, col);
		x++;
	}
}

void	draw_collectible(t_cub *cub, t_col *col)
{
	float sprite_x;
	float sprite_y;
	float angle_to_sprite;
	
	
	sprite_x = col->x * 64 - cub->player->x;
	sprite_y = col->y * 64 - cub->player->y;
	angle_to_sprite = atan2(sprite_y, sprite_x) - cub->player->angle;
	while (angle_to_sprite > PI)
		angle_to_sprite -= 2 * PI;
	while (angle_to_sprite < - PI)
		angle_to_sprite += 2 * PI;
	col->sprite_screen_x = (angle_to_sprite / (PI / 6)) * (cub->screen.width / 2) + (cub->screen.width
			/ 2);
	col->dist = sqrt(sprite_x * sprite_x + sprite_y * sprite_y);
	col->sprite_height = (64 / col->dist) * (cub->screen.width / 2) / (tan(PI
				/ 6));
	col->sprite_height = col->sprite_height / SPRITE_SCALE;
	col->bob = sin(get_time() * BOB_SPEED) * BOB_AMPLITUDE;
	render_collectible_x(cub, col);
}