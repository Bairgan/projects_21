/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:55:22 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:55:23 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	proverka(char const *set, char p)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == p)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	size_t	i;
	char	*trim;

	begin = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[begin] && proverka(set, s1[begin]))
		begin++;
	end = ft_strlen(s1);
	while (end > begin && proverka(set, s1[end - 1]))
		end--;
	trim = (char *)malloc((end - begin) + 1);
	if (!trim)
		return (NULL);
	while (begin < end)
		*(trim + i++) = *(s1 + begin++);
	*(trim + i) = '\0';
	return (trim);
}
