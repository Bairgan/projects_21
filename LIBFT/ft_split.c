/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:18:54 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/14 03:11:07 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((i < ft_strlen(s)) && s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			j++;
			while ((s[i] == c) && (s[i] != '\0'))
				i++;
		}
		i++;
	}
	return (j);
}

static size_t	ft_len(char const *s, char c, int j)
{
	int	i;
	int	a;

	i = j;
	while (s[j] != c && s[j] != '\0')
		j++;
	a = j - i;
	return (a);
}

static void	ft_free(char **s, int i)
{
	while (!s[i] && i != 0)
	{
		free(s[i]);
		i--;
	}
}

static char	*ft_string(char const *s, char c, int i, char **str2)
{
	char	*str;

	str = ft_substr((char *)s, i, ft_len(s, c, i));
	if (!str)
	{
		ft_free(str2, (i - 1));
		return (NULL);
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	if (s[i] != c && s[i] != '\0')
	{
		str[j++] = ft_string(s, c, i, str);
		i = ft_len(s, c, i);
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || s[i - 1] == 0))
			str[j++] = ft_string(s, c, i, str);
		i++;
	}
	str[j] = NULL;
	return (str);
}
