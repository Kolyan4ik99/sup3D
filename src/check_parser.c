/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:14:55 by cclock            #+#    #+#             */
/*   Updated: 2021/04/27 04:14:58 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			inits_keys(t_all *all)
{
	if (all->flag.move_a == 1 || all->flag.move_d == 1 || all->flag.move_w == 1
	|| all->flag.move_s == 1 || all->flag.rot_r == 1 || all->flag.rot_l == 1)
		draw_frame(all, 1);
	return (0);
}

int			check_resol(t_all *all)
{
	if (all->tex.r.width < 0 || all->tex.r.height < 0)
		return (-1);
	if (all->tex.r.width < 64)
		all->tex.r.width = 64;
	if (all->tex.r.height < 64)
		all->tex.r.height = 64;
	if (all->tex.r.height > 2880)
		all->tex.r.height = 2880;
	if (all->tex.r.width > 5120)
		all->tex.r.width = 5120;
	if (all->tex.r.width / 3 > all->tex.r.height)
		all->tex.r.height = all->tex.r.width / 3;
	if (all->tex.r.height / 3 > all->tex.r.width)
		all->tex.r.width = all->tex.r.height / 3;
	return (0);
}

static int	check_xpm(t_all *all)
{
	int		i;
	int		j;

	i = 0;
	while (i <= 4)
	{
		j = 0;
		if (!all->tex.tex[i].name)
			return (-1);
		while (all->tex.tex[i].name[j])
			++j;
		if (j > 4 && all->tex.tex[i].name[j -
		1] == 'm'
		&& all->tex.tex[i].name[j - 2] == 'p'
		&& all->tex.tex[i].name[j - 3] == 'x'
		&& all->tex.tex[i].name[j - 4] == '.')
			++i;
		else
			return (-1);
	}
	return (0);
}

int			check_map(t_all *all)
{
	int		i;
	int		j;
	char	**map;

	map = all->map;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2' || map[i][j] == '0')
			{
				if (i == 0 || i == all->lines - 1 || map[i][j + 1] == '\0'
					|| map[i][j + 1] == ' ' || map[i][j - 1] == ' ' ||
					!map[i - 1][j] || !map[i + 1][j] || map[i - 1][j] == ' ' ||
					map[i + 1][j] == ' ')
					return (-1);
			}
			j++;
		}
	}
	return (0);
}

int			check_all(t_all *all)
{
	if (check_xpm(all) == -1)
		ft_exit("Error\nBad format xpm file\n");
	if (check_map(all) == -1)
		ft_exit("Error\nBad map\n");
	if (!all->flag.f_det)
		ft_exit("Bad file\nEmpty floor\n");
	if (!all->flag.c_det)
		ft_exit("Bad file\nEmpty ceil\n");
	return (0);
}
