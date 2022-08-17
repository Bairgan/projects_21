/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:56:13 by mclotild          #+#    #+#             */
/*   Updated: 2022/01/02 13:53:13 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_left(char *str, int len, t_flags *flags, int minus)
{
	if (minus == 1)
	{
		ft_putchar('-', flags);
		flags->g_width--;
	}
	if (flags->g_dot > -1)
	{
		while (len > ft_strlen(str))
		{
			ft_putchar('0', flags);
			len--;
			flags->g_width--;
		}
	}
	if (len != 0)
		ft_putstr(str, flags);
	while (flags->g_width > len)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
}

void	ft_format_right_help(int minus, t_flags *flags, int len)
{
	if (minus == 1 && flags->g_width > 0)
		flags->g_width--;
	while (flags->g_width > len && flags->g_zero == -1)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
}

void	ft_format_right(char *str, int len, t_flags *flags, int minus)
{
	ft_format_right_help(minus, flags, len);
	if (minus == 1)
		ft_putchar('-', flags);
	if (flags->g_dot > -1)
	{
		while (len > ft_strlen(str))
		{
			ft_putchar('0', flags);
			len--;
		}
	}
	if (flags->g_zero == 1)
	{
		while (flags->g_width > ft_strlen(str))
		{
			ft_putchar('0', flags);
			flags->g_width--;
		}
	}
	if (len != 0)
		ft_putstr(str, flags);
}

void	ft_printf_d(long nbr, t_flags *flags)
{
	char	*str;
	int		minus;
	int		len;

	minus = 0;
	if (nbr < 0)
		minus = 1;
	if (nbr < 0)
		nbr *= -1;
	str = ft_itoa_p(nbr, 10);
	len = ft_strlen(str);
	if ((flags->g_dot > -1 && flags->g_dot > len)
		|| (nbr == 0 && flags->g_dot == 0))
	{
		len = flags->g_dot;
	}
	if (!(flags->g_width == -1 && flags->g_dot == 0 && nbr == 0)
		&& !(flags->g_width == 0 && flags->g_dot == 0 && nbr == 0))
	{
		if (flags->g_minus == 1)
			ft_format_left(str, len, flags, minus);
		else
			ft_format_right(str, len, flags, minus);
	}
	free(str);
}
