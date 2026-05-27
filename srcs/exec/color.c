/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:27:53 by hbray             #+#    #+#             */
/*   Updated: 2026/05/27 11:43:32 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_color(t_img *img, int x, int y)
{
	char	*src;

	if (x > 0 && y > 0 && img->width > x && img->height > y)
	{
		src = img->data + (y * img->size_line + x * img->bpp / 8);
		return (*(int *)src);
	}
	return (0);
}

void	draw_ceiling(int start_y, int i, t_cub *cub)
{
	int	y;

	y = 0;
	while (y < start_y)
	{
		put_pixel(i, y, 0xFFFF00, cub);
		y++;
	}
}

void	draw_floor(int end, int i, t_cub *cub)
{
	int	y;

	y = end;
	while (y < cub->texture->height)
	{
		put_pixel(i, y, 0xFF0000, cub);
		y++;
	}
}

void	draw_wall(int start_y, int end, int i, t_cub *cub)
{
	int		y;
	int		tex_y;
	float	step;
	float	tex_pos;
	int		color;

	step = (float)cub->texture[cub->dda.texture].height / cub->dda.wall_height;
	if (start_y < 0)
		start_y = 0;
	tex_pos = (start_y - cub->screen.height / 2 + cub->dda.wall_height / 2)
		* step;
	y = start_y;
	while (y < end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= cub->texture[cub->dda.texture].height)
			tex_y = cub->texture[cub->dda.texture].height - 1;
		tex_pos += step;
		color = get_color(&cub->texture[cub->dda.texture], cub->dda.texture_x,
				tex_y);
		put_pixel(i, y, color, cub);
		y++;
	}
}
