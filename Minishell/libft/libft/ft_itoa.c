/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:53:15 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 15:07:57 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_count(int str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (i + 1);
	while (str != 0)
	{
		str /= 10;
		i++;
	}
	return (i);
}

char	*ft_copy_dig(char *str, int i2, int buf)
{
	str[i2] = '\0';
	str[--i2] = (buf % 10) + 48;
	while (buf > 0)
	{
		buf /= 10;
		str[--i2] = (buf % 10) + 48;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i2;
	int		buf;

	str = NULL;
	if (n == -2147483647 - 1)
		return (ft_strdup("-2147483648"));
	i2 = str_count(n);
	buf = n;
	if (n < 0)
	{
		buf = n * -1;
		i2++;
	}
	str = (char *)malloc(i2 + 1);
	if (!str)
		return (NULL);
	str = ft_copy_dig(str, i2, buf);
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
