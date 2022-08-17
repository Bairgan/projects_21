/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:59:28 by dswarm            #+#    #+#             */
/*   Updated: 2021/07/14 12:53:53 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_string(char *str, int *len)
{
	if (str == NULL)
		ft_putstr("(null)", len);
	else
		ft_putstr(str, len);
}

void	ft_putpercent(char format, va_list ap, int *len)
{
	if (format == 'c')
		ft_putchar(va_arg (ap, int), len);
	if (format == 's')
		ft_string(va_arg (ap, char *), len);
	if (format == 'p')
		ft_putp((unsigned long long)va_arg (ap, void *), 'a', len);
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg (ap, int), len);
	if (format == 'u')
		ft_nbrun(va_arg (ap, unsigned int), len);
	if (format == 'x')
		ft_putx(va_arg (ap, unsigned int), 'a', len);
	if (format == 'X')
		ft_putx(va_arg (ap, unsigned int), 'A', len);
	if (format == '%')
		ft_putchar ('%', len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	va_start (ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_putpercent(format[i], ap, &len);
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end (ap);
	return (len);
}
