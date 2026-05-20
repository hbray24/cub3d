/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:06 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/20 16:45:31 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1280
# define HEIGHT 720

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define SPEED 2
# define ANGLE_SPEED 0.05
# define PI 3.14159265359

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dda
{
	float		delta_dist_x;
	float		delta_dist_y;
	float		side_dist_x;
	float		side_dist_y;
	float		angle_x;
	float		angle_y;
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
	bool		rotate_left;
	bool		rotate_right;
}				t_player;

typedef struct s_cub
{
	t_player	*player;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	char		**map;
}				t_cub;

t_cub			*create_cub(void);
t_player		*create_player(void);
void			all_free(t_cub **cub, t_player **player);
void			open_win(t_cub *cub);
void			put_pixel(int x, int y, int color, t_cub *cub);
void			draw_line(t_player *player, t_cub *cub, float start_x, int i);
void			*ft_memset(void *b, int c, size_t len);
void			draw_square(int x, int y, int size, int color, t_cub *cub);
void			draw_direction_ray(t_cub *cub);
int				close_win(t_cub *cub);
int				key_press(int keycode, t_player *player);
int				key_release(int keycode, t_player *player);
int				draw_loop(t_cub *cub);


#endif
