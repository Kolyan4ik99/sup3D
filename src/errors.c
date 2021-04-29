/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:15:38 by cclock            #+#    #+#             */
/*   Updated: 2021/04/27 04:15:40 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->win.addr + (y * all->win.line_l + x * (all->win.bpp / 8));
	*(unsigned int *)dst = color;
}

int			ft_exit(char *code)
{
	write(1, code, ft_strlen(code));
	exit(0);
}
