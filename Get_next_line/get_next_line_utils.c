/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:37:09 by dswarm            #+#    #+#             */
/*   Updated: 2021/07/11 20:05:43 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr (char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;
	size_t	n;

	n = ft_strlen(s1);
	str = ft_calloc(n + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin2(char *s1, char *s2, int len)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = ft_calloc((ft_strlen(s1) + len + 2), 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	c = 0;
	while (s2[c] != '\0' && (int )c < len)
		str[i++] = s2[c++];
	ft_free(&s1);
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t n)
{
	void	*a;
	char	*s;

	a = malloc(count * n);
	if (!a)
		return (NULL);
	s = (char *)a;
	while (n--)
		*s++ = '\0';
	return (a);
}
