/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:16:15 by cclock            #+#    #+#             */
/*   Updated: 2021/04/27 04:16:18 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			check_pos(t_frm *fram, t_all *all)
{
	int		n;

	n = 0;
	if (fram->side == 0)
	{
		if (fram->map_x > all->plr.pos_x)
			n = 2;
		else
			n = 3;
	}
	else
	{
		if (fram->map_y > all->plr.pos_y)
			n = 1;
	}
	return (n);
}

int			color_text(t_opt *tex, int x, int y)
{
	char	*dst;
	int		color;

	dst = tex->addr + (y * tex->line_l + x * (tex->bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

static void	free_tex(t_opt *tex)
{
	tex->en = 0;
	tex->line_l = 0;
	tex->h = 0;
	tex->w = 0;
	tex->img = 0;
	tex->addr = 0;
}

int			init_tex(t_all *all)
{
	int		i;

	i = -1;
	while (++i <= 4)
	{
		free_tex(&all->tex.tex[i]);
		all->tex.tex[i].img = mlx_xpm_file_to_image(all->win.mlx,
				all->tex.tex[i].name, &all->tex.tex[i].w, &all->tex.tex[i].h);
		if (!all->tex.tex[i].img)
			return (-5);
		all->tex.tex[i].addr = mlx_get_data_addr(all->tex.tex[i].img,
			&all->tex.tex[i].bpp, &all->tex.tex[i].line_l, &all->tex.tex[i].en);
		if (!all->tex.tex[i].addr)
			return (-5);
	}
	return (0);
}
