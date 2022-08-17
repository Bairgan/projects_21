/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:53:48 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:54:04 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	char			*d;
	const char		*s;
	size_t			c;

	d = destination;
	s = source;
	c = 0;
	if (source != 0 || destination != 0)
	{
		while (c < n)
		{
			d[c] = s[c];
			c++;
		}
		return (d);
	}
	return (NULL);
}
