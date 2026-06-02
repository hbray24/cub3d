/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:27:53 by hbray             #+#    #+#             */
/*   Updated: 2026/06/02 09:30:16 by hbray            ###   ########.fr       */
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

void	put_pixel(int x, int y, int color, t_cub *cub)
{
	char	*dst;

	if (x > 0 && y > 0 && cub->screen.width > x && cub->screen.height > y)
	{
		dst = cub->screen.data + (y * cub->screen.size_line + x
				* (cub->screen.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_ceiling(int start_y, int i, t_cub *cub)
{
	int	y;

	y = 0;
	while (y < start_y)
	{
		put_pixel(i, y, cub->para->ceiling_c, cub);
		y++;
	}
}

void	draw_floor(int end, int i, t_cub *cub)
{
	int	y;

	y = end;
	while (y < cub->screen.height)
	{
		put_pixel(i, y, cub->para->floor_c, cub);
		y++;
	}
}

int	draw_open_door(t_cub *cub, int start_y)
{
	float	lvl;
	int		offset;

	lvl = get_door_lvl(cub, cub->dda.map_x, cub->dda.map_y);
	offset = (int)(cub->dda.wall_height * lvl);
	start_y += offset;
	return (start_y);
}

void	draw_wall(int start_y, int end, int i, t_cub *cub)
{
	int		y;
	int		tex_y;
	float	step;
	float	tex_pos;
	int		color;

	if (cub->dda.texture == EXIT)
		cub->tex_w_e = &cub->exit_texture[cub->exit_anim.current_frame];
	else
		cub->tex_w_e = &cub->texture[cub->dda.texture];
	step = (float)cub->tex_w_e->height / cub->dda.wall_height;
	if (cub->dda.texture == DOOR)
		start_y = draw_open_door(cub, start_y);
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
		if (tex_y >= cub->tex_w_e->height)
			tex_y = cub->tex_w_e->height - 1;
		tex_pos += step;
		color = get_color(cub->tex_w_e, cub->dda.texture_x,
				tex_y);
		put_pixel(i, y, color, cub);
		y++;
	}
}
