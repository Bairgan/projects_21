/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_bonus3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:44:48 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/15 19:18:08 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra_b(t_arrs *arrs)
{
	int	temp;
	int	i;

	i = arrs->lena - 1;
	temp = arrs->a[arrs->lena - 1];
	while (i > 0)
	{
		arrs->a[i] = arrs->a[i - 1];
		i--;
	}
	arrs->a[0] = temp;
	return (0);
}

int	rrb_b(t_arrs *arrs)
{
	int	temp;
	int	i;

	i = arrs->lenb - 1;
	temp = arrs->b[arrs->lenb - 1];
	while (i > 0)
	{
		arrs->b[i] = arrs->b[i - 1];
		i--;
	}
	arrs->b[0] = temp;
	return (0);
}

int	rrr_b(t_arrs *arrs)
{
	int	temp;
	int	i;

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
	return (0);
}
