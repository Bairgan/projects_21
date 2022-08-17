/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:35:00 by dswarm            #+#    #+#             */
/*   Updated: 2021/12/25 23:20:45 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t n)
{
	void	*a;
	char	*s;

	a = malloc(count * n);
	if (!a)
		return (NULL);
	s = (char *)a;
	while (n--)
		*s++ = '\0';
	return (a);
}
