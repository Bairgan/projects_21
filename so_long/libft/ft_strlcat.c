/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:07:27 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/12 19:32:04 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	a;
	size_t	b;
	size_t	i;

	a = 0;
	b = 0;
	i = 0;
	while (src[a])
		a++;
	while (dst[b])
		b++;
	if (n == 0)
		return (a);
	while ((b + i) < (n - 1) && (i < a))
	{
		dst[b + i] = src[i];
		i++;
	}
	dst[b + i] = '\0';
	if (b > (n - 1))
		return (a + n);
	return (a + b);
}
