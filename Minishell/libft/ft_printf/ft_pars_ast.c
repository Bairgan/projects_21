/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:56:00 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:56:01 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_star2(t_flags *flags, const char *str, va_list ap)
{
	int	i;

	i = 1;
	if (*(++str) == '*')
	{
		flags->g_dot = va_arg(ap, int);
		i += 1;
		if (flags->g_dot < 0 && flags->g_zero == 0)
		{
			flags->g_zero = 1;
			flags->g_dot = -1;
		}
	}
	if (*str >= '0' && *str <= '9')
	{
		while (*str >= '0' && *str <= '9')
		{
			flags->g_dot = flags->g_dot * 10 + (*str - '0');
			str++;
			i++;
		}
		if (flags->g_zero == 0)
			flags->g_zero = -1;
	}
	return (i);
}

int	ft_star(t_flags *flags, va_list ap)
{
	int	i;

	i = 1;
	if (flags->g_width == -1)
	{
		flags->g_width = va_arg(ap, int);
		if (flags->g_width < 0)
		{
			flags->g_minus = 1;
			flags->g_width *= -1;
		}
	}
	return (i);
}
