/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:18:45 by cclock            #+#    #+#             */
/*   Updated: 2021/03/03 12:18:46 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void		draw_floor(t_all *all, int x, int draw_end)
{
	int		color;
	int		y;

	color = get_rgb(all->tex.f.r, all->tex.f.g, all->tex.f.b);
	y = draw_end;
	while (y < all->tex.r.height)
	{
		my_mlx_pixel_put(all, x, y, color);
		++y;
	}
}

void		draw_ceil(t_all *all, int x, int draw_start)
{
	int		color;
	int		y;

	color = get_rgb(all->tex.c.r, all->tex.c.g, all->tex.c.b);
	y = 0;
	while (y < draw_start)
	{
		my_mlx_pixel_put(all, x, y, color);
		++y;
	}
}
