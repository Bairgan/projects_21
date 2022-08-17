/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:53:55 by mclotild          #+#    #+#             */
/*   Updated: 2022/01/21 14:01:26 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	unsigned char	*r;
	unsigned char	*t;

	i = 0;
	r = (unsigned char *)s1;
	t = (unsigned char *)s2;
	while (r[i] || t[i])
	{
		if (r[i] != t[i])
			return (r[i] - t[i]);
		i++;
	}
	return (0);
}