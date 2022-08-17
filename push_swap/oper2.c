/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:05:32 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/14 23:18:47 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_arrs *arrs)
{
	int	temp;
	int	i;

	if (arrs->lena > 1)
		arrs->count++;
	i = 0;
	temp = arrs->a[0];
	while (i < arrs->lena - 1)
	{
		arrs->a[i] = arrs->a[i + 1];
		i++;
	}
	arrs->a[arrs->lena - 1] = temp;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_arrs *arrs)
{
	int	temp;
	int	i;

	if (arrs->lenb > 1)
		arrs->count++;
	i = 0;
	temp = arrs->b[0];
	while (i < arrs->lenb - 1)
	{
		arrs->b[i] = arrs->b[i + 1];
		i++;
	}
	arrs->b[arrs->lenb - 1] = temp;
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_arrs *arrs)
{
	int	temp;
	int	i;

	arrs->count++;
	i = 0;
	temp = arrs->a[0];
	while (i < arrs->lena - 1)
	{
		arrs->a[i] = arrs->a[i + 1];
		i++;
	}
	arrs->a[arrs->lena - 1] = temp;
	i = 0;
	temp = arrs->b[0];
	while (i < arrs->lenb - 1)
	{
		arrs->b[i] = arrs->b[i + 1];
		i++;
	}
	arrs->b[arrs->lenb - 1] = temp;
	write(1, "rr\n", 3);
	return (0);
}

int	rra(t_arrs *arrs)
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
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_arrs *arrs)
{
	int	temp;
	int	i;

	arrs->count++;
	i = arrs->lenb - 1;
	temp = arrs->b[arrs->lenb - 1];
	while (i > 0)
	{
		arrs->b[i] = arrs->b[i - 1];
		i--;
	}
	arrs->b[0] = temp;
	write(1, "rrb\n", 4);
	return (0);
}
