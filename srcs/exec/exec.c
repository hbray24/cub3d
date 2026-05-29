/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:33:40 by hbray             #+#    #+#             */
/*   Updated: 2026/05/29 18:23:59 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	clear_image(t_cub *cub)
{
	ft_memset(cub->screen.data, 0, cub->screen.height * cub->screen.size_line);
}

int	draw_loop(t_cub *cub)
{
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;
	int			j;

	i = 0;
	player = cub->player;
	move_player(cub);
	clear_image(cub);
	fraction = PI / 3 / cub->screen.width;
	start_x = player->angle - PI / 6;
	while (i < cub->screen.width)
	{
		draw_line(player, cub, start_x, i);
		start_x += fraction;
		i++;
	}
	j = 0;
	while (j < cub->para->nb_collec)
	{
		if (!cub->col[j].collect)
		{
			anim_maj(&cub->col[j].anim, get_time());
			draw_collectible(cub, &cub->col[j]);
		}
		j++;
	}
	draw_minimap(cub);
	render_hud(cub);
	anim_maj(&cub->hud_anim, get_time());
	anim_maj(&cub->exit_anim, get_time());
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.img, 0, 0);
	return (0);
}
