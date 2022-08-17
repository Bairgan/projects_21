/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:42:41 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/10 17:31:03 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i + start] != '\0' && i < len)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;
	size_t	a;

	if (!s)
		return (NULL);
	a = ft_strlen(s);
	str = malloc(ft_len(s, start, len) + 1);
	n = 0;
	if (!str)
		return (0);
	if ((unsigned int)a < start)
	{
		str[n] = '\0';
		return (&str[n]);
	}
	while (n < len && s[start])
	{
		str[n] = ((char *)s)[start];
		start++;
		n++;
	}
	str[n] = '\0';
	return (str);
}
