/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:31:25 by dswarm            #+#    #+#             */
/*   Updated: 2021/12/25 23:22:52 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lstr(char *s1, char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

static size_t	ft_rstr(char *s1, char *set)
{
	size_t	i;

	if (ft_lstr(s1, set) == ft_strlen(s1))
		return (0);
	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i--;
	return (ft_strlen(s1) - 1 - i);
}

char	*ft_strtrim(char *s1, char *set)
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
