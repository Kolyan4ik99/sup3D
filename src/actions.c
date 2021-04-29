/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:16:19 by cclock            #+#    #+#             */
/*   Updated: 2021/03/03 12:16:21 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	move_w(t_all *all)
{
	if (all->map[(int)(all->plr.pos_x + all->speed.dx)]
					[(int)all->plr.pos_y] != '1')
		all->plr.pos_x += all->speed.dx;
	if (all->map[(int)all->plr.pos_x]
		[(int)(all->plr.pos_y + all->speed.dy)] != '1')
		all->plr.pos_y += all->speed.dy;
	return (0);
}

int	move_s(t_all *all)
{
	if (all->map[(int)(all->plr.pos_x - all->speed.dx)]
					[(int)all->plr.pos_y] != '1')
		all->plr.pos_x -= all->speed.dx;
	if (all->map[(int)all->plr.pos_x]
		[(int)(all->plr.pos_y - all->speed.dy)] != '1')
		all->plr.pos_y -= all->speed.dy;
	return (0);
}

int	move_a(t_all *all)
{
	if (all->map[(int)(all->plr.pos_x - all->speed.sx)]
					[(int)all->plr.pos_y] != '1')
		all->plr.pos_x -= all->speed.sx;
	if (all->map[(int)all->plr.pos_x]
		[(int)(all->plr.pos_y - all->speed.sy)] != '1')
		all->plr.pos_y -= all->speed.sy;
	return (0);
}

int	move_d(t_all *all)
{
	if (all->map[(int)(all->plr.pos_x + all->speed.sx)]
					[(int)all->plr.pos_y] != '1')
		all->plr.pos_x += all->speed.sx;
	if (all->map[(int)all->plr.pos_x]
		[(int)(all->plr.pos_y + all->speed.sy)] != '1')
		all->plr.pos_y += all->speed.sy;
	return (0);
}
