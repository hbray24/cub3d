/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbray <hbray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:06 by mmusquer          #+#    #+#             */
/*   Updated: 2026/06/02 10:08:36 by hbray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "animation.h"
# include "libft.h"
# include "parser.h"
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

# define WIDTH 4096
# define HEIGHT 720
# define W 119
# define A 97
# define S 115
# define D 100
# define SPACE 32
# define LEFT 65361
# define RIGHT 65363
# define SPEED 300
# define ANGLE_SPEED 3.0
# define PI 3.14159265359
# define ANIM_SPEED_COL 0.08
# define ANIM_SPEED_HUD 0.2
# define LENGTH 50
# define SPRITE_SCALE 4
# define SPRITE_HEIGHT 200
# define BOB_SPEED 2.0
# define BOB_AMPLITUDE 30.0

typedef struct s_para	t_para;
typedef struct s_col	t_col;

typedef enum s_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	DOOR,
	EXIT
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

typedef struct s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct s_door
{
	int					x;
	int					y;
	int					state;
	float				open_lvl;
	double				timer;
	bool				is_open;
}						t_door;

typedef struct s_cub
{
	t_player			*player;
	t_dda				dda;
	t_img				col_texture[6];
	t_img				texture[5];
	t_img				screen;
	t_img				hud_texture[6];
	t_img				*tex_w_e;
	t_anim				hud_anim;
	t_img				exit_texture[6];
	t_anim				exit_anim;
	t_para				*para;
	t_col				*col;
	t_door				*door;
	float				wall_dist[WIDTH];
	void				*mlx;
	void				*win;
	double				time;
	double				old_time;
}						t_cub;

t_cub					*create_cub(void);
t_player				*create_player(void);
t_para					*create_para(void);
void					all_free(t_para **para, t_cub **cub);
void					free_player(t_player **player);
void					open_win(t_cub *cub);
void					put_pixel(int x, int y, int color, t_cub *cub);
void					draw_line(t_player *player, t_cub *cub, float start_x,
							int i);
void					draw_minimap(t_cub *cub);
void					move_player(t_cub *cub, double frametime);
int						get_color(t_img *img, int x, int y);
void					draw_wall(int end, int start_y, int i, t_cub *cub);
void					draw_floor(int end, int i, t_cub *cub);
void					draw_ceiling(int start_y, int i, t_cub *cub);
int						close_win(t_cub *cub);
int						key_press(int keycode, t_cub *cub);
int						key_release(int keycode, t_player *player);
int						draw_loop(t_cub *cub);
void					destroy_image_1(t_cub **cub);
void					destroy_image_2(t_cub **cub);
void					open_door(t_cub *cub);
void					uptade_doors(t_cub *cub, double frametime);
void					init_doors(t_cub *cub, t_para *para);
float					get_door_lvl(t_cub *cub, int x, int y);


#endif
