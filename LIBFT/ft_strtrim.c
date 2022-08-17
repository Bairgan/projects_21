/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:31:25 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/09 18:16:42 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lstr(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

static size_t	ft_rstr(char const *s1, char const *set)
{
	size_t	i;

	if (ft_lstr(s1, set) == ft_strlen(s1))
		return (0);
	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i--;
	return (ft_strlen(s1) - 1 - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	l;
	size_t	r;

	i = 0;
	if (!s1)
		return (NULL);
	l = ft_lstr(s1, set);
	r = ft_rstr(s1, set);
	str = malloc ((ft_strlen(s1) - l - r) + 1);
	if (!str)
		return (NULL);
	while (i != (ft_strlen(s1) - l - r))
	{
		str[i] = s1[i + l];
		i++;
	}
	str[i] = '\0';
	return (str);
}
