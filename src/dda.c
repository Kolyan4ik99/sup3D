/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:15:19 by cclock            #+#    #+#             */
/*   Updated: 2021/04/27 04:15:21 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda(t_all *all, t_frm *fram)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (fram->side_dist_x < fram->side_dist_y)
		{
			fram->side_dist_x += fram->delta_dist_x;
			fram->map_x += fram->step_x;
			fram->side = 0;
		}
		else
		{
			fram->side_dist_y += fram->delta_dist_y;
			fram->map_y += fram->step_y;
			fram->side = 1;
		}
		if (all->map[fram->map_x][fram->map_y] == '1')
			hit = 1;
	}
}

void	calc_fl_ceil(t_all *all, t_frm *fram)
{
	if (fram->side == 0)
		fram->perp_wall_dist = (fram->map_x - all->plr.pos_x +
				(1 - fram->step_x) / 2) / fram->ray_dir_x;
	else
		fram->perp_wall_dist = (fram->map_y - all->plr.pos_y +
				(1 - fram->step_y) / 2) / fram->ray_dir_y;
	if (fram->line_height == 0)
		fram->line_height = all->tex.r.height;
	else
		fram->line_height = (int)(all->tex.r.height / fram->perp_wall_dist);
	fram->draw_start = -fram->line_height / 2 + all->tex.r.height / 2;
	if (fram->draw_start < 0)
		fram->draw_start = 0;
	fram->draw_end = fram->line_height / 2 + all->tex.r.height / 2;
	if (fram->draw_end >= all->tex.r.height)
		fram->draw_end = all->tex.r.height - 1;
}

void	step_side_dist(t_all *all, t_frm *fram)
{
	if (fram->ray_dir_x < 0)
	{
		fram->step_x = -1;
		fram->side_dist_x = (all->plr.pos_x -
				(double)fram->map_x) * fram->delta_dist_x;
	}
	else
	{
		fram->step_x = 1;
		fram->side_dist_x = (fram->map_x + 1.0 - all->plr.pos_x)
				* fram->delta_dist_x;
	}
	if (fram->ray_dir_y < 0)
	{
		fram->step_y = -1;
		fram->side_dist_y = (all->plr.pos_y - fram->map_y)
				* fram->delta_dist_y;
	}
	else
	{
		fram->step_y = 1;
		fram->side_dist_y = (fram->map_y + 1.0 - all->plr.pos_y)
				* fram->delta_dist_y;
	}
}

void	init_fram(t_all *all, t_frm *fram, int x)
{
	fram->camera_x = (double)(2 * x) / (double)all->tex.r.width - 1;
	fram->ray_dir_x = all->plr.dir_x + all->plr.plane_x * fram->camera_x;
	fram->ray_dir_y = all->plr.dir_y + all->plr.plane_y * fram->camera_x;
	fram->map_x = (int)all->plr.pos_x;
	fram->map_y = (int)all->plr.pos_y;
	fram->delta_dist_x = sqrt(1 + (fram->ray_dir_y *
			fram->ray_dir_y) / (fram->ray_dir_x * fram->ray_dir_x));
	fram->delta_dist_y = sqrt(1 + (fram->ray_dir_x *
			fram->ray_dir_x) / (fram->ray_dir_y * fram->ray_dir_y));
}
