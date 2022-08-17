/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:02:59 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/12 18:11:49 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_neg(int n, int j, int i, char *str)
{
	long	s;

	s = n;
	if (n < 0)
	{
		s *= -1;
		while (j != 0)
		{
			str[j - 1] = s % 10 + '0';
			s = s / 10;
			j--;
		}
		str[0] = '-';
		str[i] = '\0';
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		j;
	int		i;

	j = ft_count(n);
	str = (char *)malloc((sizeof(char) * (j + 1)));
	if (!str)
		return (NULL);
	i = j;
	if (n == 0)
		str[0] = '0';
	ft_neg(n, j, i, str);
	if (n < 0)
		return (str);
	if (n > 0)
	{
		while (j != 0)
		{
			str[j - 1] = n % 10 + '0';
			n = n / 10;
			j--;
		}
	}
	str[i] = '\0';
	return (str);
}
