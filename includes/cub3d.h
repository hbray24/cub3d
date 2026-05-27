/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:06 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/27 13:40:42 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define ESC 65307

# define WIDTH 1280
# define HEIGHT 720
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define SPEED 8
# define ANGLE_SPEED 0.1
# define PI 3.14159265359

typedef struct e_para	t_para;

typedef enum s_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}						t_dir;

typedef struct s_dda
{
	float				delta_dist_x;
	float				delta_dist_y;
	float				side_dist_x;
	float				side_dist_y;
	float				angle_x;
	float				angle_y;
	float				pos_x;
	float				pos_y;
	float				wall_height;
	int					step_x;
	int					step_y;
	int					map_x;
	int					map_y;
	int					side;
	int					texture;
	int					texture_x;
}						t_dda;

typedef struct s_player
{
	float				x;
	float				y;
	float				angle;
	bool				key_up;
	bool				key_down;
	bool				key_right;
	bool				key_left;
	bool				rotate_left;
	bool				rotate_right;
}						t_player;

typedef struct s_img
{
	void				*img;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct s_cub
{
	t_player			*player;
	t_dda				dda;
	t_img				texture[4];
	t_img				screen;
	t_para				*para;
	void				*mlx;
	void				*win;
}						t_cub;

# include "parser.h"

t_cub					*create_cub(void);
t_player				*create_player(void);
t_para					*create_para(void);
void					all_free(t_para **para);
void					free_player(t_player **player);
void					open_win(t_cub *cub);
void					put_pixel(int x, int y, int color, t_cub *cub);
void					draw_line(t_player *player, t_cub *cub, float start_x,
							int i);
void					draw_square(int x, int y, int size, int color,
							t_cub *cub);
void					draw_direction_ray(t_cub *cub);
void					move_player(t_cub *cub);
void					draw_wall(int end, int start_y, int i, t_cub *cub);
void					draw_floor(int end, int i, t_cub *cub);
void					draw_ceiling(int start_y, int i, t_cub *cub);
int						close_win(t_cub *cub);
int						key_press(int keycode, t_cub *cub);
int						key_release(int keycode, t_player *player);
int						draw_loop(t_cub *cub);

#endif
