/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:56:26 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:56:27 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flags	flags;

	va_start(ap, str);
	flags.g_res = 0;
	ft_cleanflags(&flags);
	pars(str, ap, &flags);
	va_end(ap);
	return (flags.g_res);
}
