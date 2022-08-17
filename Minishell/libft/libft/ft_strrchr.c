/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:55:19 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:55:20 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		d;
	char	*str;
	char	buk;

	str = (char *)s;
	buk = (char)c;
	d = (int)ft_strlen(str);
	while (d >= 0)
	{
		if (str[d] == buk)
			return (&str[d]);
		else
			d--;
	}
	return (NULL);
}
