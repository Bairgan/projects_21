/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:56:16 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:56:17 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pprint_left(t_flags *flags, char *str, int len)
{
	ft_putstr("0x", flags);
	while (len > ft_strlen(str))
	{
		ft_putchar('0', flags);
		len--;
	}
	ft_putstr(str, flags);
	while (flags->g_width > len)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
}

void	ft_pprint_right(t_flags *flags, char *str, int len)
{
	while (flags->g_width > len)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
	while (len > ft_strlen(str))
	{
		ft_putchar('0', flags);
		len--;
	}
	ft_putstr("0x", flags);
	ft_putstr(str, flags);
}

void	ft_printf_p(int *nbr, t_flags *flags)
{
	char				*str;
	unsigned long int	c;
	int					len;

	c = (unsigned long int)nbr;
	str = ft_itoa_p(c, 16);
	len = ft_strlen(str);
	if (flags->g_dot > 0 && flags->g_dot > len)
		len = flags->g_dot;
	flags->g_width -= 2;
	if (flags->g_minus == -1)
		ft_pprint_right(flags, str, len);
	else
		ft_pprint_left(flags, str, len);
	free(str);
}
