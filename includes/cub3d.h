/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:57:23 by cclock            #+#    #+#             */
/*   Updated: 2021/02/15 19:57:26 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MY_CUB3D_H
# define CUB_MY_CUB3D_H

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define L 123
# define R 124

# include "math.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct	s_speed
{
	double		dx;
	double		dy;
	double		sy;
	double		sx;
	double		rot;
}				t_speed;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_size
{
	int			height;
	int			width;
}				t_size;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				t_win;

typedef struct	s_flag
{
	short		move_w;
	short		move_s;
	short		move_d;
	short		move_a;
	short		rot_r;
	short		rot_l;
	short		map_det;
	short		res_det;
	char		no_det:1;
	char		so_det:1;
	char		we_det:1;
	char		ea_det:1;
	char		s_det:1;
	char		c_det:1;
	char		f_det:1;
}				t_flag;

typedef struct	s_text_draw
{
	int			num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			color;
}				t_text_draw;

typedef struct	s_sprite_draw
{
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transf_x;
	double		transf_y;
	int			spr_screen_x;
	int			spr_height;
	int			spr_width;
	int			draw_start_y;
	int			draw_start_x;
	int			draw_end_y;
	int			draw_end_x;
	int			tex_x;
	int			tex_y;
	int			d;
	int			color;
}				t_sprite_draw;

typedef struct	s_opt
{
	char		*name;
	void		*img;
	void		*addr;
	int			en;
	int			line_l;
	int			bpp;
	int			h;
	int			w;
}				t_opt;

typedef struct	s_tex
{
	t_size		r;
	t_opt		tex[5];
	t_rgb		f;
	t_rgb		c;
}				t_tex;

typedef struct	s_frm
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	short		side;
	int			line_height;
	int			draw_end;
	int			draw_start;
	int			map_x;
	int			map_y;
}				t_frm;

typedef struct	s_plr
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_plr;

typedef struct	s_spr
{
	double		x;
	double		y;
	double		dist;
}				t_spr;

typedef struct	s_all
{
	char		**map;
	t_plr		plr;
	t_win		win;
	t_tex		tex;
	t_list		*head;
	t_speed		speed;
	t_flag		flag;
	t_list		*main_head;
	int			cnt_sprit;
	int			lines;
	double		*buffer;
}				t_all;

int				parse(t_all *all, char *argv);
int				digest(t_all *all, char *line, int rd);
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
int				fill_resol(t_all *all, char *line, int count);
int				fill_f_col(t_all *all, char *line, int count);
int				fill_c_col(t_all *all, char *line, int count);
int				fill_no_tex(t_all *all, char *line);
int				fill_so_tex(t_all *all, char *line);
int				fill_we_tex(t_all *all, char *line);
int				fill_ea_tex(t_all *all, char *line);
int				fill_s_tex(t_all *all, char *line);
void			make_map(t_all *all);
int				fill_map(t_all *all, char *line);
int				fill_map_sec(t_all *all, char *line);
void			free_struct(t_all *all);
int				draw_frame(t_all *all, int flag);
void			draw_line(t_all *all, t_frm *frm, int x);
void			draw_text(t_all *all, int x, t_frm *fram);
int				move_w(t_all *all);
int				move_s(t_all *all);
int				move_a(t_all *all);
int				move_d(t_all *all);
void			draw_ceil(t_all *all, int x, int draw_start);
void			draw_floor(t_all *all, int x, int draw_end);
int				turn_right(t_all *all, double rotspeed);
int				turn_left(t_all *all, double rotspeed);
int				key_prs(int keycode, t_all *all);
int				key_rls(int keycode, t_all *all);
int				key_close(int keycode, t_all *all);
int				check_resol(t_all *all);
void			start_srct(t_all *all);
int				main(int argc, char *argv[]);
int				ft_exit(char *code);
int				start_mlx(t_all *all, int point);
int				init_tex(t_all *all);
int				check_pos(t_frm *fram, t_all *all);
int				color_text(t_opt *tex, int x, int y);
int				create_bitmap(t_all *all);
void			bubble_sort(t_all *all, t_spr *spr);
int				dist(t_spr *spr, t_all *all);
void			print_sprite(t_all *all, t_spr *sprite);
void			init_sprite(t_all *all);
void			dda(t_all *all, t_frm *fram);
void			calc_fl_ceil(t_all *all, t_frm *fram);
void			step_side_dist(t_all *all, t_frm *fram);
void			init_fram(t_all *all, t_frm *fram, int x);
int				check_all(t_all *all);
void			find_plr(t_all *all, int x, int y);
void			fill_sprit(t_all *all, t_spr *spr);
int				check_rgb(t_all *all, int type);
int				inits_keys(t_all *all);

#endif
