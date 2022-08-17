/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:52:51 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:52:52 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t					i;
	unsigned char			*d;

	d = s;
	i = 0;
	while (i < n)
	{
		d[i] = '\0';
		i++;
	}
}
