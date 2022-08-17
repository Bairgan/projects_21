/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_wd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:56:02 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:56:03 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		flags->g_width = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			flags->g_width = flags->g_width * 10 + (str[i] - '0');
			i++;
		}
	}
	return (i);
}

void	ft_dot(const char *str, t_flags *flags)
{
	while (*str != 's' && *str != 'c' && *str != 'x'
		&& *str != 'X' && *str != 'i' && *str != 'd'
		&& *str != 'u' && *str != 'p' && *str != '\0')
	{
		if (*str == '.')
			flags->g_dot = 0;
		str++;
	}
}
