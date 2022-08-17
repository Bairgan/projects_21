/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:43:00 by dswarm            #+#    #+#             */
/*   Updated: 2021/12/21 23:37:10 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	neg;
	long	num;

	i = 0;
	num = 0;
	neg = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i]) == ' ')
		i++;
	if (str[i] == '-')
		neg = 1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (((str[i] >= 48) && (str[i] <= 57)))
	{
		num = num * 10;
		num = num + (str[i++] - '0');
	}
	if (neg == 1)
		return (-num);
	return (num);
}
