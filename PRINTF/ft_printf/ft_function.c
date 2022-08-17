/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:59:26 by dswarm            #+#    #+#             */
/*   Updated: 2021/07/14 13:00:01 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr(int n, int *len)
{
	int		i;
	char	str[11];

	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = n * -1;
	}
	i = 0;
	if (n == 0)
		ft_putchar('0', len);
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}

void	ft_putstr(char *s, int *len)
{
	if (s)
		while (*s)
			ft_putchar(*(s++), len);
}

void	ft_nbrun(unsigned int n, int *len)
{
	int		i;
	char	str[10];

	i = 0;
	if (n == 0)
		ft_putchar('0', len);
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}

void	ft_putx(unsigned int n, int a, int *len)
{
	int		i;
	char	str[10];

	i = 0;
	if (n == 0)
		ft_putchar('0', len);
	while (n != 0)
	{
		if (n % 16 > 9)
			str[i++] = (n % 16) - 10 + a;
		else
			str[i++] = n % 16 + '0';
		n = n / 16;
	}
	while (i--)
		ft_putchar(str[i], len);
}

void	ft_putp(unsigned long long n, int a, int *len)
{
	int		i;
	char	str[30];

	ft_putstr("0x", len);
	i = 0;
	if (n == 0)
		ft_putchar('0', len);
	while (n != 0)
	{
		if (n % 16 > 9)
			str[i++] = (n % 16) - 10 + a;
		else
			str[i++] = n % 16 + '0';
		n = n / 16;
	}
	while (i--)
		ft_putchar(str[i], len);
}
