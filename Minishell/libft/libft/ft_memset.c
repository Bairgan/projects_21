/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:54:15 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:54:15 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(char *s, int c, size_t n)
{
	unsigned char	*mas;
	unsigned char	ch;

	mas = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n)
	{
		*mas++ = ch;
		n--;
	}
	return (s);
}
