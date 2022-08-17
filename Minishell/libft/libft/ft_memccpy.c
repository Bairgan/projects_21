/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:53:39 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:53:40 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	unsigned char		symbol;
	size_t				i;

	symbol = (unsigned char)c;
	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
		if (s[i - 1] == symbol)
			return (&d[i]);
	}
	return (NULL);
}
