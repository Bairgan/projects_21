/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:17:03 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/15 23:23:38 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa_b(t_arrs *arrs)
{
	int	temp;

	if (arrs->lena > 1)
	{
		temp = arrs->a[0];
		arrs->a[0] = arrs->a[1];
		arrs->a[1] = temp;
	}
	return (0);
}

int	sb_b(t_arrs *arrs)
{
	int	temp;

	if (arrs->lenb > 1)
	{
		temp = arrs->b[0];
		arrs->b[0] = arrs->b[1];
		arrs->b[1] = temp;
		return (0);
	}
	else
		return (-1);
}

int	ss_b(t_arrs *arrs)
{
	int	temp;

	if (arrs->lena > 1)
	{
		temp = arrs->a[0];
		arrs->a[0] = arrs->a[1];
		arrs->a[1] = temp;
	}
	else
		return (-1);
	if (arrs->lenb > 1)
	{
		temp = arrs->b[0];
		arrs->b[0] = arrs->b[1];
		arrs->b[1] = temp;
	}
	else
		return (-1);
	return (0);
}

int	pb_b(t_arrs *arrs)
{
	int		i;

	if (arrs->lena < 1)
		return (-1);
	i = arrs->lenb - 1;
	while (i > -1)
	{
		arrs->b[i + 1] = arrs->b[i];
		i--;
	}
	arrs->b[0] = arrs->a[0];
	arrs->lenb++;
	i = 0;
	while (i < arrs->lena - 1)
	{
		arrs->a[i] = arrs->a[i + 1];
		i++;
	}
	arrs->lena--;
	return (0);
}

int	pa_b(t_arrs *arrs)
{
	int		i;

	if (arrs->lenb > 0)
	{
		if (arrs->lenb == 0)
			return (-1);
		i = arrs->lena - 1;
		while (i > -1)
		{
			arrs->a[i + 1] = arrs->a[i];
			i--;
		}
		arrs->a[0] = arrs->b[0];
		arrs->lena++;
		i = 0;
		while (i < arrs->lenb - 1)
		{
			arrs->b[i] = arrs->b[i + 1];
			i++;
		}
		arrs->lenb--;
	}
	return (-1);
}
