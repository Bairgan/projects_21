/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:56:08 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 12:20:54 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_pars(t_flags *flags)
{
	if (flags->g_dot == -1 && flags->g_zero == 0)
		flags->g_zero = 1;
	if (flags->g_zero == 0)
		flags->g_zero = -1;
}

void	ft_cleanflags(t_flags *flags)
{
	flags->g_width = -1;
	flags->g_minus = -1;
	flags->g_dot = -1;
	flags->g_zero = -1;
}

void	ft_argument(t_flags *flags, va_list ap, const char *str)
{
	if (*str == 's')
		ft_printf_s(va_arg(ap, char *), flags);
	else if (*str == 'c')
		ft_printf_c(va_arg(ap, int), flags);
	if (*str == 'd')
		ft_printf_d(va_arg(ap, int), flags);
	else if (*str == 'i')
		ft_printf_d(va_arg(ap, int), flags);
	else if (*str == 'u')
		ft_printf_u(va_arg (ap, unsigned int), flags);
	else if (*str == 'p')
		ft_printf_p(va_arg(ap, int *), flags);
	else if (*str == 'x')
		ft_printf_x(va_arg(ap, unsigned int), flags);
	else if (*str == 'X')
		ft_printf_x_up(va_arg(ap, unsigned int), flags);
}

void	pars(const char *str, va_list ap, t_flags *flags)
{
	while (*str)
	{
		if (*str == '%' && *(++str))
		{
			str += ft_zero(str, flags);
			if (*str != '0')
				str += ft_width(flags, str);
			if (*str == '*')
				str += ft_star(flags, ap);
			if (*str == '.')
				str += ft_star2(flags, str, ap);
			add_pars(flags);
			if (*str == 's' || *str == 'c' || *str == 'x' || *str == 'X'
				|| *str == 'd' || *str == 'i' || *str == 'u' || *str == 'p')
				ft_argument(flags, ap, str);
			else
				ft_printf_c(*str, flags);
		}
		else
			ft_putchar(*str, flags);
		ft_cleanflags(flags);
		str++;
	}
}
