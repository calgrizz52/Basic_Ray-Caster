/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <calgrizz52@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 09:36:15 by mkok              #+#    #+#             */
/*   Updated: 2017/05/31 12:13:51 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# define WIN_W 512
# define WIN_H 384
# define KEY_ESC 53
# define KEY_0 29
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 89
# define KEY_8 28
# define KEY_9 25
# define KEY_MOUSE_CLIC_L 1
# define KEY_MOUSE_CLIC_R 2
# define KEY_MOUSE_UP 5
# define KEY_MOUSE_DOWN 4
# define KEY_MOUSE_LEFT 7
# define KEY_MOUSE_RIGHT 6
# define KEY_KP_DOT 65
# define KEY_KP_ENTER 76
# define KEY_KP_0 82
# define KEY_KP_1 83
# define KEY_KP_2 84
# define KEY_KP_3 85
# define KEY_KP_4 86
# define KEY_KP_5 87
# define KEY_KP_6 88
# define KEY_KP_7 89
# define KEY_KP_8 91
# define KEY_KP_9 92
# define KEY_KP_PLUS 69
# define KEY_KP_MINUS 78
# define KEY_PAGE_UP 116
# define KEY_PAGE_DOWN 121
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define KEY_PRESS_MASK (1L<<2)
# define KEY_PRESS 2

typedef struct				s_data_prop
{
	double					pos_x;
	double					pos_y;
	double					dir_x;
	double					dir_y;
	double					plane_x;
	double					plane_y;

	double					camera_x;
	double					ray_pos_x;
	double					ray_pos_y;
	double					ray_dir_x;
	double					ray_dir_y;

	int						map_x;
	int						map_y;
	double					side_dist_x;
	double					side_dist_y;
	double					delta_dist_x;
	double					delta_dist_y;
	double					perp_wall_dist;
	int						step_x;
	int						step_y;
	int						hit;
	int						side;

	int						line_height;
	int						draw_start;
	int						draw_end;

	int						poop;
	int						color;

	double					movespeed;
	double					rotspeed;

	double					old_dir_x;
	double					old_plane_x;
}							t_d_prop;

typedef struct				s_b_prop
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*pixel_img;
	int						bpp;
	int						s_line;
	int						gd;
	t_d_prop				*d;
	int						**map;
	int						map_w;
	int						map_h;
	int						draw_x0;
	int						draw_x1;
	int						draw_y0;
	int						draw_y1;
	int						value;
}							t_g_prop;

typedef struct				s_coor_prop
{
	int						x;
	int						y;
	int						color;
}							t_c_prop;

typedef struct				s_draw_prop
{
	int						dx;
	int						sx;
	int						dy;
	int						sy;
	int						err;
	int						er2;
}							t_j_prop;

t_g_prop					*init_t_g_prop(void);
void						init_t_g_prop_help(t_g_prop *g, double shit);
t_c_prop					*drawline(t_g_prop *g);
int							render_screen(t_g_prop *g);
void						clear_screen(t_g_prop *g);
void						draw_x(t_g_prop *g);
t_j_prop					drawline_help(t_g_prop *g);
void						make_map(t_g_prop *g);
void						print_map(t_g_prop *g);
void						fill_row(int x0, int x1, int row, t_g_prop *g);
void						fill_column(int y0, int y1, int col, t_g_prop *g);
void						make_maze(t_g_prop *g);
void						calc_rpos_and_rdir(t_g_prop *g);
void						calc_step_and_side_dist(t_g_prop *g);
void						perform_dda(t_g_prop *g);
void						calc_perp_lh_ds_de_color(t_g_prop *g);
void						calc_color(t_g_prop *g);
int							wolf_key_funct(int keycode, t_g_prop *g);
int							wolf_mouse_hook(int button, int x, int y,
		t_g_prop *g);
void						move_up(t_g_prop *g);
void						move_down(t_g_prop *g);
void						move_right(t_g_prop *g);
void						move_left(t_g_prop *g);
int							display_usage(int count);
void						draw_border(t_g_prop *g);

#endif
