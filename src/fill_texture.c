/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:58:10 by cclock            #+#    #+#             */
/*   Updated: 2021/03/01 18:37:02 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	fill_no_tex(t_all *all, char *line)
{
	if (all->flag.no_det)
		ft_exit("Bad map\nError NO tex\n");
	all->flag.no_det = 1;
	all->tex.tex[3].name = ft_strtrim(line, " ");
	return (0);
}

int	fill_so_tex(t_all *all, char *line)
{
	if (all->flag.so_det)
		ft_exit("Bad map\nError SO tex\n");
	all->flag.so_det = 1;
	all->tex.tex[2].name = ft_strtrim(line, " ");
	return (0);
}

int	fill_we_tex(t_all *all, char *line)
{
	if (all->flag.we_det)
		ft_exit("Bad map\nError WE tex\n");
	all->flag.we_det = 1;
	all->tex.tex[0].name = ft_strtrim(line, " ");
	return (0);
}

int	fill_ea_tex(t_all *all, char *line)
{
	if (all->flag.ea_det)
		ft_exit("Bad map\nError EA tex\n");
	all->flag.ea_det = 1;
	all->tex.tex[1].name = ft_strtrim(line, " ");
	return (0);
}

int	fill_s_tex(t_all *all, char *line)
{
	if (all->flag.s_det)
		ft_exit("Bad map\nError S tex\n");
	all->flag.s_det = 1;
	all->tex.tex[4].name = ft_strtrim(line, " ");
	return (0);
}
