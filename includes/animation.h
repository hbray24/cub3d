/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:55:10 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/29 19:08:01 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

typedef struct s_cub	t_cub;
typedef struct s_anim
{
	int					frame[6];
	int					frame_count;
	int					current_frame;
	double				last_frame;
	double				time_b_frame;
}						t_anim;

typedef struct s_col
{
	int					x;
	int					y;
	int					collect;
	int					sprite_screen_x;
	int					sprite_screen_y;
	float				dist;
	int					sprite_height;
	float				bob;
	t_anim				anim;
}						t_col;

void					pixar(t_cub *cub);
void					anim_maj(t_anim *anim, double time);
double					get_time(void);
void					draw_collectible(t_cub *cub, t_col *col);

void					init_hud(t_cub *cub);
void					init_exit(t_cub *cub);
void					render_hud(t_cub *cub);

t_col					*create_col(t_cub *cub);
void					init_img_1(t_cub *cub);

#endif