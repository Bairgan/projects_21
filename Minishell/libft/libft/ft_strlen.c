/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:55:08 by mclotild          #+#    #+#             */
/*   Updated: 2022/01/21 17:20:02 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	
	if (!s)
	{
	//	printf("J\n");
		return (0);
	}
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}