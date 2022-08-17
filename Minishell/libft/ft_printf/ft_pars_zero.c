/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:56:05 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:56:06 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_zero(const char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (*str == '0' || *str == '-')
	{
		if (*str == '-')
		{
			flags->g_minus = 1;
			if (flags->g_zero == 0)
				flags->g_zero = -1;
		}
		if (*str == '0' && flags->g_minus == -1)
			flags->g_zero = 0;
		str++;
		i++;
	}
	ft_dot(str, flags);
	return (i);
}
