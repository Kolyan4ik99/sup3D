/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 01:36:34 by cclock            #+#    #+#             */
/*   Updated: 2021/03/01 18:14:20 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(char) * (gnl_ft_strlen(s1) + gnl_ft_strlen(s2) \
				+ 1));
	if (!ptr)
		return (NULL);
	while (s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		ptr[i++] = s2[j++];
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	gnl_ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*gnl_ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		flag;

	i = 0;
	while (s1[i] != 0)
		i++;
	s2 = (char *)malloc((sizeof(char) * (i + 1)));
	if (!s2)
		return (NULL);
	flag = 0;
	while (flag < i)
	{
		s2[flag] = s1[flag];
		flag++;
	}
	s2[flag] = '\0';
	return (s2);
}

char	*gnl_ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
