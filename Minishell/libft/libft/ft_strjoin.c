/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:54:51 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:54:52 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cont;
	size_t	c1;
	size_t	c2;

	if (!s1 || !s2)
		return (NULL);
	cont = (char *)malloc(ft_strlen(s2) + (ft_strlen(s1) + 1));
	if (!cont)
		return (NULL);
	c1 = -1;
	c2 = -1;
	while (++c1 < ft_strlen(s1))
	{
		*(cont + c1) = *(s1 + c1);
	}
	while (++c2 < ft_strlen(s2))
	{
		*(cont + c1++) = *(s2 + c2);
	}
	*(cont + c1) = '\0';
	return (cont);
}
