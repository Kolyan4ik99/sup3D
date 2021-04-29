/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:07:29 by cclock            #+#    #+#             */
/*   Updated: 2020/12/29 11:40:53 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char		*gnl_ft_strdup(const char *s1);
char		*gnl_ft_strchr(char *s, char c);
int			get_next_line(int fd, char **line);
char		*gnl_ft_strjoin(char const *s1, char const *s2);
size_t		gnl_ft_strlen(const char *s);
int			gnl_find_n(char **stack, char **line);
int			gnl_read_fd(int fd, char *buf, char **stack, char **line);
int			gnl_chek_pos(int rd, char **stack, char **line);

#endif
