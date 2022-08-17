/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:56:21 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:56:22 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uprint_right(t_flags *flags, char *str, int len, int nbr)
{
	while (flags->g_width > len && flags->g_zero == -1)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
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
	if (!(nbr == 0 && flags->g_dot == 0) && len != 0)
		ft_putstr(str, flags);
}

void	ft_uprint_left(t_flags *flags, char *str, int len, int nbr)
{
	if (flags->g_dot > -1)
	{
		while (len > ft_strlen(str))
		{
			ft_putchar('0', flags);
			len--;
			flags->g_width--;
		}
	}
	if (!(nbr == 0 && flags->g_dot == 0) && len != 0)
		ft_putstr(str, flags);
	while (flags->g_width > len)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
}

void	ft_printf_u(unsigned long nbr, t_flags *flags)
{
	char	*str;
	int		len;

	str = ft_itoa_p(nbr, 10);
	len = ft_strlen(str);
	if (flags->g_dot > -1 && flags->g_dot > ft_strlen(str))
		len = flags->g_dot;
	if (flags->g_dot == 0 && nbr == 0)
		len = 0;
	if (flags->g_minus == 1)
		ft_uprint_left(flags, str, len, nbr);
	else
		ft_uprint_right(flags, str, len, nbr);
	free(str);
}
