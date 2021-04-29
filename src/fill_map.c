/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 00:16:22 by cclock            #+#    #+#             */
/*   Updated: 2021/02/26 00:16:23 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_t_list(t_list *list)
{
	free(list->content);
	free(list);
}

void		make_map(t_all *all)
{
	char	*tmp;
	int		i;
	int		size;
	t_list	*for_free;

	all->head = all->main_head;
	size = ft_lstsize(all->head);
	i = 0;
	all->map = (char **)malloc(sizeof(char *) * size + 1);
	if (!all->map)
		return ;
	while (all->head)
	{
		tmp = all->head->content;
		all->map[i++] = ft_strdup(tmp);
		for_free = all->head;
		all->head = all->head->next;
		free_t_list(for_free);
		++all->lines;
	}
	all->map[i] = NULL;
	find_plr(all, 0, 0);
}

int			fill_map(t_all *all, char *line)
{
	int		rt;

	rt = 0;
	if (!line)
		return (-1);
	all->flag.map_det = 1;
	if (!all->head)
	{
		all->head = malloc(sizeof(t_list));
		if (!all->head)
			ft_exit("Не удалось выделить память");
		all->head->content = ft_strdup(line);
		if (!all->head->content)
			ft_exit("Не удалось выделить память");
		all->head->next = NULL;
		all->main_head = all->head;
	}
	else
		rt = fill_map_sec(all, line);
	return (rt);
}

int			fill_map_sec(t_all *all, char *line)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		ft_exit("Не удалось выделить память");
	all->head->next = new_list;
	all->head = new_list;
	all->head->content = ft_strdup(line);
	if (!all->head->content)
		ft_exit("Не удалось выделить память");
	all->head->next = NULL;
	return (0);
}
