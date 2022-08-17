/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:13:19 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/08 22:52:38 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = ft_strlen((char *)s);
	while (a >= 0)
	{
		if (((char *)s)[a] == (char)c)
			return (&((char *)s)[a]);
		a--;
	}
	return (NULL);
}
