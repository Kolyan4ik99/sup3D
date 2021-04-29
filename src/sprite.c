/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:16:47 by cclock            #+#    #+#             */
/*   Updated: 2021/04/27 04:16:49 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			draw_sprite(t_all *all, t_sprite_draw spr_draw, int x)
{
	int				y;
	int				d;

	y = spr_draw.draw_start_y;
	while (y < spr_draw.draw_end_y)
	{
		d = (y) * 256 - all->tex.r.height * 128 +
				spr_draw.spr_height * 128;
		spr_draw.tex_y = ((d * all->tex.tex[4].h) / spr_draw.spr_height) / 256;
		spr_draw.color = color_text(&all->tex.tex[4], spr_draw.tex_x,
									spr_draw.tex_y);
		if ((spr_draw.color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(all, x, y,
							spr_draw.color);
		++y;
	}
}

void				init_sprite(t_all *all)
{
	t_spr			spr[all->cnt_sprit];

	fill_sprit(all, spr);
	bubble_sort(all, spr);
	print_sprite(all, spr);
}

void				calc_sprite_pos(t_all *all, t_spr *sprite,
					t_sprite_draw *spr_draw, int i)
{
	spr_draw->sprite_x = sprite[i].x - all->plr.pos_x;
	spr_draw->sprite_y = sprite[i].y - all->plr.pos_y;
	spr_draw->inv_det = 1.0 / (all->plr.plane_x * all->plr.dir_y -
			all->plr.dir_x * all->plr.plane_y);
	spr_draw->transf_x = spr_draw->inv_det * (all->plr.dir_y *
			spr_draw->sprite_x - all->plr.dir_x * spr_draw->sprite_y);
	spr_draw->transf_y = spr_draw->inv_det * (-all->plr.plane_y *
			spr_draw->sprite_x + all->plr.plane_x * spr_draw->sprite_y);
	spr_draw->spr_screen_x = (int)((all->tex.r.width / 2) *
			(1 + spr_draw->transf_x / spr_draw->transf_y));
	spr_draw->spr_height = abs((int)(all->tex.r.height / spr_draw->transf_y));
	spr_draw->draw_start_y = -spr_draw->spr_height / 2 + all->tex.r.height / 2;
	if (spr_draw->draw_start_y < 0)
		spr_draw->draw_start_y = 0;
	spr_draw->draw_end_y = spr_draw->spr_height / 2 + all->tex.r.height / 2;
	if (spr_draw->draw_end_y >= all->tex.r.height)
		spr_draw->draw_end_y = all->tex.r.height - 1;
	spr_draw->spr_width = abs((int)(all->tex.r.height / (spr_draw->transf_y)));
	spr_draw->draw_start_x = -spr_draw->spr_width / 2 + spr_draw->spr_screen_x;
	if (spr_draw->draw_start_x < 0)
		spr_draw->draw_start_x = 0;
	spr_draw->draw_end_x = spr_draw->spr_width / 2 + spr_draw->spr_screen_x;
	if (spr_draw->draw_end_x >= all->tex.r.width)
		spr_draw->draw_end_x = all->tex.r.width - 1;
}

void				print_sprite(t_all *all, t_spr *sprite)
{
	int				i;
	int				x;
	t_sprite_draw	spr_draw;

	i = 0;
	while (i < all->cnt_sprit)
	{
		calc_sprite_pos(all, sprite, &spr_draw, i);
		x = spr_draw.draw_start_x - 1;
		while (x < spr_draw.draw_end_x)
		{
			spr_draw.tex_x = (int)(256 * (x - (-spr_draw.spr_width
			/ 2 + spr_draw.spr_screen_x)) * all->tex.tex[4].w
					/ spr_draw.spr_width) / 256;
			if (spr_draw.transf_y > 0 && x > 0 &&
			x < all->tex.r.width && spr_draw.transf_y < all->buffer[x])
				draw_sprite(all, spr_draw, x);
			++x;
		}
		++i;
	}
}
