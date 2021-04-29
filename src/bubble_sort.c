/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:14:46 by cclock            #+#    #+#             */
/*   Updated: 2021/04/27 04:14:48 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			check_rgb(t_all *all, int type)
{
	if (type == 1)
	{
		if (check_resol(all))
			return (-1);
	}
	if (type == 2)
	{
		if (all->tex.f.r > 255 || all->tex.f.b > 255 || all->tex.f.g > 255)
			return (-2);
		if (all->tex.f.r < 0 || all->tex.f.b < 0 || all->tex.f.g < 0)
			return (-2);
	}
	if (type == 3)
	{
		if (all->tex.c.r > 255 || all->tex.c.b > 255 || all->tex.c.g > 255)
			return (-3);
		if (all->tex.c.r < 0 || all->tex.c.b < 0 || all->tex.c.g < 0)
			return (-3);
	}
	return (1);
}

static void	swap(t_spr *spr, int i)
{
	t_spr	tmp;

	tmp = spr[i];
	spr[i] = spr[i + 1];
	spr[i + 1] = tmp;
}

int			dist(t_spr *spr, t_all *all)
{
	int		i;

	i = 0;
	while (i < all->cnt_sprit)
	{
		spr[i].dist = ((all->plr.pos_x - spr[i].x) *
		(all->plr.pos_x - spr[i].x) + (all->plr.pos_y - spr[i].y)
		* (all->plr.pos_y - spr[i].y));
		++i;
	}
	return (0);
}

void		bubble_sort(t_all *all, t_spr *spr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	dist(spr, all);
	while (i < all->cnt_sprit - 1)
	{
		while (j < all->cnt_sprit - 1)
		{
			if (spr[j].dist < spr[j + 1].dist)
			{
				swap(spr, j);
			}
			++j;
		}
		++i;
		j = 0;
	}
}
