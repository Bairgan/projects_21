/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:54:57 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/07 23:59:32 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup (const char *s1)
{
	char	*str;
	size_t	i;
	size_t	n;

	n = ft_strlen(s1);
	str = malloc(n + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
