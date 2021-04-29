/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:25:47 by cclock            #+#    #+#             */
/*   Updated: 2021/03/03 12:25:48 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_speed(t_all *all)
{
	int	tmp;

	if (all->tex.r.width <= 2560 && all->tex.r.width > 1500)
		tmp = 2;
	else if (all->tex.r.width <= 1500 && all->tex.r.width > 700)
		tmp = 3;
	else
		tmp = 5;
	all->speed.rot = 0.04;
	if (all->tex.r.height < 500)
		all->speed.rot = 0.03;
	all->speed.dx = (double)(all->plr.dir_x / tmp);
	all->speed.dy = (double)(all->plr.dir_y / tmp);
	all->speed.sx = (double)(all->plr.plane_x / tmp);
	all->speed.sy = (double)(all->plr.plane_y / tmp);
}

void	new_draw(t_all *all)
{
	if (all->flag.move_a == 1)
		move_a(all);
	if (all->flag.move_d == 1)
		move_d(all);
	if (all->flag.move_w == 1)
		move_w(all);
	if (all->flag.move_s == 1)
		move_s(all);
	if (all->flag.rot_l == 1)
		turn_left(all, all->speed.rot);
	if (all->flag.rot_r == 1)
		turn_right(all, all->speed.rot);
}

int		key_prs(int keycode, t_all *all)
{
	init_speed(all);
	if (keycode == A)
		all->flag.move_a = 1;
	if (keycode == D)
		all->flag.move_d = 1;
	if (keycode == L)
		all->flag.rot_l = 1;
	if (keycode == R)
		all->flag.rot_r = 1;
	if (keycode == ESC)
		ft_exit("The end");
	if (keycode == W)
		all->flag.move_w = 1;
	if (keycode == S)
		all->flag.move_s = 1;
	new_draw(all);
	draw_frame(all, 1);
	return (0);
}

int		key_rls(int keycode, t_all *all)
{
	init_speed(all);
	if (keycode == A)
		all->flag.move_a = 0;
	if (keycode == D)
		all->flag.move_d = 0;
	if (keycode == L)
		all->flag.rot_l = 0;
	if (keycode == R)
		all->flag.rot_r = 0;
	if (keycode == ESC)
		ft_exit("The end");
	if (keycode == W)
		all->flag.move_w = 0;
	if (keycode == S)
		all->flag.move_s = 0;
	return (0);
}

int		key_close(int keycode, t_all *all)
{
	(void)all;
	(void)keycode;
	ft_exit("The end");
	return (0);
}
