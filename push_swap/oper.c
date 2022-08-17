/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 22:42:14 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/14 23:17:32 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_arrs *arrs)
{
	int	temp;

	if (arrs->lena > 1)
	{
		temp = arrs->a[0];
		arrs->a[0] = arrs->a[1];
		arrs->a[1] = temp;
		arrs->count++;
		write(1, "sa\n", 3);
	}
	return (0);
}

int	sb(t_arrs *arrs)
{
	int	temp;

	if (arrs->lenb > 1)
	{
		temp = arrs->b[0];
		arrs->b[0] = arrs->b[1];
		arrs->b[1] = temp;
		arrs->count++;
		write(1, "sa\n", 3);
		return (0);
	}
	return (-1);
}

int	ss(t_arrs *arrs)
{
	int	resa;
	int	resb;

	arrs->count--;
	resa = sa(arrs);
	resb = sb(arrs);
	if (resa == -1 || resb == -1)
	{
		return (-1);
	}
	return (0);
}

int	pb(t_arrs *arrs)
{
	int	i;

	if (arrs->lena < 1)
		return (-1);
	i = arrs->lenb - 1;
	while (i > -1)
	{
		arrs->b[i + 1] = arrs->b[i];
		i--;
	}
	arrs->count++;
	arrs->b[0] = arrs->a[0];
	arrs->lenb++;
	i = 0;
	while (i < arrs->lena - 1)
	{
		arrs->a[i] = arrs->a[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
	arrs->lena--;
	arrs->a[arrs->lena] = 0;
	return (0);
}

int	pa(t_arrs *arrs)
{
	int	i;

	if (arrs->lenb > 0)
	{
		if (arrs->lenb == 0)
			return (-1);
		i = arrs->lena - 1;
		arrs->count++;
		while (i > -1)
		{
			arrs->a[i + 1] = arrs->a[i];
			i--;
		}
		arrs->a[0] = arrs->b[0];
		arrs->lena++;
		i = -1;
		while (++i < arrs->lenb - 1)
			arrs->b[i] = arrs->b[i + 1];
		write(1, "pa\n", 3);
		arrs->lenb--;
		arrs->b[arrs->lenb] = 0;
		return (0);
	}
	return (-1);
}
