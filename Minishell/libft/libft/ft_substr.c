/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:55:27 by mclotild          #+#    #+#             */
/*   Updated: 2022/01/21 14:05:02 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_func(char *s, unsigned int start, size_t len)
{
	size_t	j;
	int		i;

	i = start;
	j = 0;
	while (s[i])
	{
		i++;
		j++;
	}
	if (j < len)
		return (j);
	return (len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	if (s)
		len = ft_func(s, start, len);
	i = 0;
	p = (char *)malloc(len + 1);
	if (!p || !s)
		return (NULL);
	while (len && start < ft_strlen(s))
	{
		p[i] = s[start];
		start++;
		len--;
		i++;
	}
	p[i] = '\0';
	return (p);
}
