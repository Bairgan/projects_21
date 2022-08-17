/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:30:59 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/07 19:44:11 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !source)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
		if (((unsigned char *)source)[i] == ((unsigned char)c))
		{
			((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
