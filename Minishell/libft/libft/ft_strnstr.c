/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:55:16 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:55:17 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stog, const char *igla, size_t len)
{
	size_t	i;
	size_t	t;
	size_t	j;

	i = len;
	j = 0;
	if (!*igla)
		return ((char *)stog);
	while (stog[j] && len--)
	{
		t = 0;
		if (stog[j] == igla[t])
		{
			while (igla[t] && stog[j + t] == igla[t] && j + t < i)
				t++;
			if (igla[t] == '\0')
				return ((char *)stog + j);
		}
		j++;
	}
	return (0);
}
