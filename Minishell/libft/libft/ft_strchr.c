/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:54:37 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:59:23 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*b;
	char	c;

	b = (char *)str;
	c = (char)ch;
	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] == c)
			return (&b[i]);
		else
			i++;
	}
	if (b[i] == c)
		return (&b[i]);
	return (NULL);
}
