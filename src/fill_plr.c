/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:15:50 by cclock            #+#    #+#             */
/*   Updated: 2021/04/27 04:15:52 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	char	find_ch(char ch)
{
	if (ch == 'N')
		return ('N');
	if (ch == 'W')
		return ('W');
	if (ch == 'E')
		return ('E');
	if (ch == 'S')
		return ('S');
	else
		return (0);
}

static void		fill_plr(t_all *all, double x, double y, char ch)
{
	all->plr.pos_x = x + 0.5;
	all->plr.pos_y = y + 0.5;
	if ((all->map[(int)x][(int)y] = '0') == '0' && ch == 'N')
		return ;
	if (ch == 'W')
	{
		all->plr.dir_y = -1;
		all->plr.dir_x = 0;
		all->plr.plane_y = 0;
		all->plr.plane_x = -0.66;
	}
	if (ch == 'E')
	{
		all->plr.dir_y = 1;
		all->plr.dir_x = 0;
		all->plr.plane_y = 0;
		all->plr.plane_x = 0.66;
	}
	if (ch == 'S')
	{
		all->plr.dir_y = 0;
		all->plr.dir_x = 1;
		all->plr.plane_y = -0.66;
		all->plr.plane_x = 0;
	}
}

void			fill_sprit(t_all *all, t_spr *spr)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	x = 0;
	y = 0;
	while (all->map[y])
	{
		while (all->map[y][x])
		{
			if (all->map[y][x] == '2')
			{
				spr[i].x = y + 0.5;
				spr[i].y = x + 0.5;
				++i;
			}
			++x;
		}
		x = 0;
		++y;
	}
}

void			find_plr(t_all *all, int x, int y)
{
	short		count;
	char		ch;

	count = 0;
	while (all->map[y])
	{
		while (all->map[y][x])
		{
			ch = find_ch(all->map[y][x]);
			if (ch && ++count)
			{
				fill_plr(all, y, x, ch);
			}
			else if (all->map[y][x] == '2')
				++all->cnt_sprit;
			if (!ch && (all->map[y][x] != ' ' && all->map[y][x] != '0'
			&& all->map[y][x] != '1' && all->map[y][x] != '2'))
				ft_exit("Map error\nExtra char\n");
			++x;
		}
		x = 0;
		++y;
	}
	if (count != 1)
		ft_exit("Bad map\nError player\n");
}
