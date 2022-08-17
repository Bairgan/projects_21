/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:28:59 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/12 18:41:04 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !source)
		return (NULL);
	if ((unsigned char *)source < (unsigned char *)dest)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)source)[n];
	else
	{
		while (n--)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
			i++;
		}
	}
	return (dest);
}
