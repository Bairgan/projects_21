/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:53:42 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:53:43 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	symbol;

	str = (unsigned char *)s;
	symbol = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == symbol)
			return (&str[i]);
		else
			i++;
	}
	return (NULL);
}
