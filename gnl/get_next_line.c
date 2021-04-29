/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:09:01 by cclock            #+#    #+#             */
/*   Updated: 2021/03/01 18:27:23 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_find_n(char **stack, char **line)
{
	char	*new_line;
	char	*tmp_stack;

	new_line = gnl_ft_strchr(*stack, '\n');
	if (new_line)
	{
		new_line[0] = '\0';
		tmp_stack = *stack;
		*line = gnl_ft_strdup(tmp_stack);
		if (!*line)
		{
			free(tmp_stack);
			return (-1);
		}
		*stack = gnl_ft_strdup(&new_line[1]);
		free(tmp_stack);
		if (!*stack)
			return (-1);
		return (1);
	}
	else
		return (0);
}

int	gnl_read_fd(int fd, char *buf, char **stack, char **line)
{
	int		rd;
	int		flag;
	char	*tmp_stack;

	flag = 0;
	rd = 1;
	while (flag == 0 && (rd > 0))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = '\0';
		if (!*stack)
			*stack = gnl_ft_strdup("");
		if (!*stack)
			return (-1);
		tmp_stack = *stack;
		*stack = gnl_ft_strjoin(tmp_stack, buf);
		free(tmp_stack);
		if (!*stack)
			return (-1);
		if (gnl_find_n(stack, line) == 1)
			flag = 1;
	}
	if (rd > 0 && flag == 1)
		return (1);
	return (0);
}

int	gnl_chek_pos(int rd, char **stack, char **line)
{
	if (rd != 0 || !*stack || !*stack[0])
	{
		if (rd == 0)
		{
			*line = gnl_ft_strdup("");
			if (!*line)
				return (-1);
		}
		return (rd);
	}
	*line = *stack;
	*stack = NULL;
	return (rd);
}

int	get_next_line(int fd, char **line)
{
	static char	*stack;
	int			rd;
	char		buf[BUFFER_SIZE + 1];

	if ((!line) || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	if (stack)
	{
		rd = gnl_find_n(&stack, line);
		if (rd == 1)
			return (1);
		if (rd == -1)
			return (-1);
	}
	rd = gnl_read_fd(fd, buf, &stack, line);
	if (rd == -1)
		return (-1);
	return (gnl_chek_pos(rd, &stack, line));
}
