/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:58:18 by mclotild          #+#    #+#             */
/*   Updated: 2022/01/21 18:39:43 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_strcat(char **dest, char **src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	i = ft_strlen(*dest);
	if (i == 0)
	{
	//	printf("H\n");
		*dest = ft_strdup(*src);
	}
	else if ((*src))
	{
		while ((*src)[j] != '\0')
		{
			(*dest)[i + j] = (*src)[j];
			j++;
		}
		(*dest)[i + j] = '\0';
	}
}
