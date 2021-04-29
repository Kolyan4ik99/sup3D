/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_re_c_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:05:37 by cclock            #+#    #+#             */
/*   Updated: 2021/03/01 18:41:18 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_punk(char *line, int *i)
{
	int	cnt;

	cnt = 0;
	while (line[*i] && (line[*i] == ' ' || line[*i] == ','))
	{
		if (line[*i] == ',')
			++cnt;
		if (cnt > 1)
			return (-4);
		(*i)++;
	}
	return (cnt);
}

static int	fill_rgb(char *line, int *i)
{
	int		num;

	num = 0;
	while (line[*i] && line[*i] >= '0' && line[*i] <= '9')
	{
		num = line[*i] - '0';
		++(*i);
		while (line[*i] >= '0' && line[*i] <= '9' && line[*i])
		{
			num *= 10;
			num += line[*i] - '0';
			++(*i);
		}
	}
	if (num < 0)
		return (-1);
	return (num);
}

int			fill_resol(t_all *all, char *line, int count)
{
	int		i;
	int		num;

	if (all->flag.res_det)
		ft_exit("Bad map\nResolution error!\n");
	all->flag.res_det = 1;
	i = 0;
	while (line[i])
	{
		while (line[i] && (line[i] < '0' || line[i] > '9'))
			++i;
		num = fill_rgb(line, &i);
		if (num < 1)
			ft_exit("Bad map\nResolution error!\n");
		if (count == 0)
			all->tex.r.width = num;
		if (count++ == 1)
			all->tex.r.height = num;
	}
	if (count != 2 || check_rgb(all, 1) == -1)
		ft_exit("Bad map\nResolution error!\n");
	return (0);
}

int			fill_f_col(t_all *all, char *line, int count)
{
	int		i;
	int		num;
	int		cnt;

	i = 0;
	cnt = 0;
	if (all->flag.map_det || all->flag.f_det)
		ft_exit("Bad map\nFloor error!\n");
	all->flag.f_det = 1;
	while (line[i])
	{
		while (line[i] && (line[i] < '0' || line[i] > '9'))
			++i;
		num = fill_rgb(line, &i);
		if (count == 0 && (cnt += check_punk(line, &i)) == 1)
			all->tex.f.r = num;
		if (count == 1 && (cnt += check_punk(line, &i)) == 2)
			all->tex.f.g = num;
		if (count++ == 2 && (cnt += check_punk(line, &i)) == 2)
			all->tex.f.b = num;
	}
	if (count != 3 || check_rgb(all, 2) == -2 || cnt != 2)
		ft_exit("Bad map\nFloor error!\n");
	return (0);
}

int			fill_c_col(t_all *all, char *line, int count)
{
	int		i;
	int		num;
	int		cnt;

	i = 0;
	cnt = 0;
	if (all->flag.map_det || all->flag.c_det)
		ft_exit("Bad map\nCeil error!\n");
	while (line[i] && (all->flag.c_det = 1) == -1)
	{
		while (line[i] && (line[i] < '0' || line[i] > '9'))
			++i;
		num = fill_rgb(line, &i);
		if (num == -1)
			return (-7);
		if (count == 0 && (cnt += check_punk(line, &i)) == 1)
			all->tex.c.r = num;
		if (count == 1 && (cnt += check_punk(line, &i)) == 2)
			all->tex.c.g = num;
		if (count++ == 2 && (cnt += check_punk(line, &i)) == 2)
			all->tex.c.b = num;
	}
	if (count != 3 || check_rgb(all, 3) == -3 || cnt != 2)
		ft_exit("Bad map\nCeil error!\n");
	return (0);
}
