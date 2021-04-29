/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:57:16 by cclock            #+#    #+#             */
/*   Updated: 2021/04/26 22:57:19 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_more_text(int x, t_frm *fram, t_text_draw *tex, t_all *all)
{
	int		y;
	int		size_y;

	size_y = fram->draw_end;
	y = fram->draw_start;
	while (y < size_y)
	{
		tex->tex_y = (int)tex->tex_pos & (all->tex.tex[tex->num].h - 1);
		tex->tex_pos += tex->step;
		tex->color = color_text((&all->tex.tex[tex->num]), tex->tex_x,
				tex->tex_y);
		my_mlx_pixel_put(all, x, y, tex->color);
		++y;
	}
}

void		draw_text(t_all *all, int x, t_frm *fram)
{
	t_text_draw	tex;

	tex.num = check_pos(fram, all);
	if (fram->side == 0)
		tex.wall_x = all->plr.pos_y + fram->perp_wall_dist * fram->ray_dir_y;
	else
		tex.wall_x = all->plr.pos_x + fram->perp_wall_dist * fram->ray_dir_x;
	tex.wall_x -= floor(tex.wall_x);
	tex.tex_x = (int)(tex.wall_x * (double)all->tex.tex[tex.num].w);
	if (fram->side == 0 && fram->ray_dir_x > 0)
		tex.tex_x = all->tex.tex[tex.num].w - tex.tex_x - 1;
	if (fram->side == 1 && fram->ray_dir_y < 0)
		tex.tex_x = all->tex.tex[tex.num].w - tex.tex_x - 1;
	tex.step = 1.0 * all->tex.tex[tex.num].h / fram->line_height;
	tex.tex_pos = (fram->draw_start - all->tex.r.height
			/ 2 + fram->line_height / 2) * tex.step;
	draw_more_text(x, fram, &tex, all);
}

void		draw_line(t_all *all, t_frm *fram, int x)
{
	draw_ceil(all, x, fram->draw_start);
	draw_text(all, x, fram);
	draw_floor(all, x, fram->draw_end);
}

int			draw_frame(t_all *all, int flag)
{
	int		x;
	t_frm	frame;
	double	buffer[all->tex.r.width];

	x = 0;
	all->buffer = buffer;
	while (x < all->tex.r.width)
	{
		init_fram(all, &frame, x);
		step_side_dist(all, &frame);
		dda(all, &frame);
		calc_fl_ceil(all, &frame);
		draw_line(all, &frame, x);
		all->buffer[x] = frame.perp_wall_dist;
		++x;
	}
	if (all->cnt_sprit > 0)
		init_sprite(all);
	if (flag)
		mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	return (0);
}
