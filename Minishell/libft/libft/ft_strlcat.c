/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:54:55 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:54:56 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] && i < dsize)
		i++;
	while (src[j] && (i + j + 1) < dsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < dsize)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
