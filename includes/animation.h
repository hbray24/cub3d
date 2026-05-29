/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:55:10 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/29 11:21:18 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

typedef struct s_anim
{
	int		frame[6];
	int		frame_count;
	int		current_frame;
	double	last_frame;
	double	time_b_frame;
}			t_anim;

typedef struct s_col
{
	int		x;
	int		y;
	int		collect;
	t_anim	anim;
}			t_col;

void		pixar(t_cub *cub);
double		get_time(void);

t_col		*create_col(t_cub *cub);
void		init_img_1(t_cub *cub);

#endif