/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:06 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/20 09:32:43 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CU3D_H

# define WIDTH 1280
# define HEIGHT 720

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_dda
{
	float		delta_dist_x;
	float		delta_dist_y;
	float		side_dist_x;
	float		side_dist_y;
	float		ray_x;
	float		ray_y;
	float		pos_x;
	float		pos_y;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			side;
}				t_dda;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
	bool		key_up;
	bool		key_down;
	bool		key_right;
	bool		key_left;
	bool		left_rotate;
	bool		right_rotate;
}				t_player;

typedef struct s_cub
{
	t_player	player;
	void		*mlx;
	void		*win;
	void		*img;
	void		*data;
	int			bpp;
	int			size_line;
	int			endian;
	char		**map;
}				t_cub;

#endif
