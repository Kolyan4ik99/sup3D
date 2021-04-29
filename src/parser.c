/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:17:29 by cclock            #+#    #+#             */
/*   Updated: 2021/02/15 18:18:00 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			digest(t_all *all, char *line, int rd)
{
	if ('R' == line[0])
		return (fill_resol(all, &line[1], 0));
	else if ('N' == line[0] && 'O' == line[1])
		return (fill_no_tex(all, &line[2]));
	else if ('S' == line[0] && 'O' == line[1])
		return (fill_so_tex(all, &line[2]));
	else if ('W' == line[0] && 'E' == line[1])
		return (fill_we_tex(all, &line[2]));
	else if ('E' == line[0] && 'A' == line[1])
		return (fill_ea_tex(all, &line[2]));
	else if ('S' == line[0])
		return (fill_s_tex(all, &line[1]));
	else if ('F' == line[0])
		return (fill_f_col(all, &line[1], 0));
	else if ('C' == line[0])
		return (fill_c_col(all, &line[1], 0));
	else if (ft_strchr(line, '1'))
		return (fill_map(all, line));
	else if (line[0] != '\0')
		ft_exit("Bad map\nExtra line\n");
	else if (line[0] == '\0' && all->flag.map_det && rd != 0)
		ft_exit("Bad map\nExtra line\n");
	return (0);
}

int			parse(t_all *all, char *argv)
{
	int		fd;
	int		rd;
	char	*line;
	int		num_cod;

	line = NULL;
	fd = open(argv, O_RDONLY);
	(fd < 1) ? ft_exit("Error\nBad file\n") : 0;
	rd = 1;
	while (rd == 1)
	{
		rd = get_next_line(fd, &line);
		num_cod = digest(all, line, rd);
		if (num_cod > 0)
		{
			free(line);
			return (num_cod);
		}
		free(line);
	}
	if (rd)
		return (-1);
	close(fd);
	make_map(all);
	return (0);
}
