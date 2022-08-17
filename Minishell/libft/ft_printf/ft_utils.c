/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:56:32 by mclotild          #+#    #+#             */
/*   Updated: 2022/01/02 13:54:06 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->g_res++;
}

void	ft_putstr(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], flags);
		i++;
	}
}

int	ft_itoa_add(int len, unsigned long t, int b)
{
	while (t > 0)
	{
		t /= b;
		len++;
	}
	return (len);
}

char	*ft_itoa_p(unsigned long nbr, int base)
{
	unsigned long	temp_nbr;
	int				len;
	char			*str;

	temp_nbr = nbr;
	len = 0;
	str = NULL;
	if (nbr == 0)
		len++;
	len = ft_itoa_add(len, temp_nbr, base);
	str = malloc(len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
			str[len - 1] += 'a' - 10;
		else
			str[len - 1] = str[len - 1] + '0';
		nbr /= base;
		len--;
	}
	return (str);
}
