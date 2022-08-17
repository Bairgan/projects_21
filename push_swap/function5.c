/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:28:52 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/14 23:27:25 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_push_global(t_arrs *arrs)
{
	int	i;

	i = 0;
	ft_rotate_line(arrs);
	while (arrs->lenb)
		ft_push_a(arrs);
	return (0);
}

int	ft_sort_global(t_arrs *arrs)
{
	if (ft_check_sort(arrs) != 0 || ft_cond_sort(arrs) != 0)
	{
		ft_find_line(arrs);
		ft_push_global(arrs);
	}
	return (0);
}
