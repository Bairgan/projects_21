/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:31:15 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/14 23:37:54 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_opt1(t_arrs *arrs, int i, int j, int *min)
{
	*min = i + arrs->lenb - j;
	arrs->brot = j - arrs->lenb;
	if (arrs->lenb < 3)
		arrs->brot = arrs->brot + 3;
	arrs->arot = i + 1;
}

void	choose_opt(t_arrs *arrs, int i, int j, int *min)
{
	if (i < arrs->lena - i && j < arrs->lenb - j && i + j < *min)
	{
		*min = i + j;
		arrs->brot = j;
		arrs->arot = i + 1;
	}
	else if (i < arrs->lena - i && j > arrs->lenb - j && i
		+ arrs->lenb - j < *min)
		choose_opt1(arrs, i, j, min);
	else if (i >= arrs->lena - i && j > arrs->lenb - j && arrs->lena - i
		+ arrs->lenb - j < *min)
	{
		*min = arrs->lena - i + arrs->lenb - j;
		arrs->brot = j - arrs->lenb;
		arrs->arot = i - arrs->lena + 1;
	}
	else if (i >= arrs->lena - i && j < arrs->lenb - j && arrs->lena - i
		+ j < *min)
	{
		*min = arrs->lena - i + j;
		arrs->brot = j;
		arrs->arot = i - arrs->lena + 1;
	}
}

void	ft_rotater(t_arrs *arrs)
{
	if (arrs->arot > 0 && arrs->brot > 0)
		dadb(arrs);
	else if (arrs->arot > 0 && arrs->brot < 0)
		daub(arrs);
	else if (arrs->arot < 0 && arrs->brot < 0)
		uaub(arrs);
	else if (arrs->arot < 0 && arrs->brot > 0)
		uadb(arrs);
	else if (arrs->arot > 0 && arrs->brot == 0)
		da0b(arrs);
	else if (arrs->arot < 0 && arrs->brot == 0)
	{
		rra(arrs);
		arrs->arot++;
	}
	else if (arrs->arot == 0 && arrs->brot > 0)
	{
		rb(arrs);
		arrs->brot--;
	}
	else if (arrs->arot == 0 && arrs->brot < 0)
	{
		rrb(arrs);
		arrs->brot++;
	}
}

int	ft_rotate(t_arrs *arrs)
{
	int	i;
	int	j;
	int	min;

	min = 10000;
	j = -1;
	while (++j < arrs->lenb)
	{
		i = -1;
		while (++i < arrs->lena)
			if (arrs->b[j] > arrs->a[i] && arrs->b[j] < arrs->a[i + 1])
				break ;
		choose_opt(arrs, i, j, &min);
	}
	while (arrs->arot != 0 || arrs->brot != 0)
	{
		ft_rotater(arrs);
	}
	return (0);
}

void	ft_push_a(t_arrs *arrs)
{
	while (arrs->lenb)
	{
		if (arrs->b[0] < arrs->a[0] && arrs->b[0] > arrs->a[arrs->lena - 1])
			pa(arrs);
		else
			ft_rotate(arrs);
	}
	while (ft_check_sort(arrs) != 0)
	{
		if (ft_check_sort(arrs) == 1)
			ra(arrs);
		else
			rra(arrs);
	}
}
