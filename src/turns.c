/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:22:42 by cclock            #+#    #+#             */
/*   Updated: 2021/03/03 12:22:43 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			turn_right(t_all *all, double rotspeed)
{
	double	old_x;
	double	oldplane_x;

	rotspeed = 0.1;
	oldplane_x = all->plr.plane_x;
	old_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(-rotspeed) -
			all->plr.dir_y * sin(-rotspeed);
	all->plr.dir_y = old_x * sin(-rotspeed) + all->plr.dir_y * cos(rotspeed);
	all->plr.plane_x = all->plr.plane_x * cos(-rotspeed) -
			all->plr.plane_y * sin(-rotspeed);
	all->plr.plane_y = oldplane_x * sin(-rotspeed) +
			all->plr.plane_y * cos(-rotspeed);
	return (0);
}

int			turn_left(t_all *all, double rotspeed)
{
	double	old_x;
	double	oldplane_x;

	oldplane_x = all->plr.plane_x;
	rotspeed = 0.1;
	old_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(rotspeed) -
			all->plr.dir_y * sin(rotspeed);
	all->plr.dir_y = old_x * sin(rotspeed) + all->plr.dir_y * cos(rotspeed);
	all->plr.plane_x = all->plr.plane_x * cos(rotspeed) -
			all->plr.plane_y * sin(rotspeed);
	all->plr.plane_y = oldplane_x * sin(rotspeed) +
			all->plr.plane_y * cos(rotspeed);
	return (0);
}
