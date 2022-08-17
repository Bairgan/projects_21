/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:56:26 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/06 21:43:31 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	a;
	size_t	b;
	size_t	i;
	char	*s;

	i = 0;
	b = ft_strlen((char *)needle);
	s = (char *)haystack;
	if (b == 0 || haystack == needle)
		return (s);
	while (s[i] != '\0' && i < n)
	{
		a = 0;
		while (s[i + a] == needle[a] && s[i + a] != '\0')
		{
			if ((i + a) >= n)
				return (0);
			a++;
			if (needle[a] == '\0')
				return (&s[i]);
		}
		i++;
	}
	return (0);
}
