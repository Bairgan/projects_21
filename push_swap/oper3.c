/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:07:43 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/14 23:19:04 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrr(t_arrs *arrs)
{
	int	temp;
	int	i;

	arrs->count++;
	i = arrs->lena - 1;
	temp = arrs->a[arrs->lena - 1];
	while (i > 0)
	{
		arrs->a[i] = arrs->a[i - 1];
		i--;
	}
	arrs->a[0] = temp;
	i = arrs->lenb - 1;
	temp = arrs->b[arrs->lenb - 1];
	while (i > 0)
	{
		arrs->b[i] = arrs->b[i - 1];
		i--;
	}
	arrs->b[0] = temp;
	write(1, "rrr\n", 4);
	return (0);
}
