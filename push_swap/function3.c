/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:00:37 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/14 23:23:22 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_line(t_arrs *arrs)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < arrs->lena)
	{
		if (arrs->a[i] < arrs->a[i + 1])
			j++;
		if (arrs->a[i] > arrs->a[i + 1])
		{
			if (j > arrs->mlen)
			{
				arrs->mlen = j;
				arrs->ind = i;
			}
			j = 1;
		}
		i++;
	}
	arrs->linemax = arrs->a[arrs->ind];
	arrs->linemin = arrs->a[arrs->ind + 1 - arrs->mlen];
}

static	int	ft_ra_i(t_arrs *arrs, int i)
{
	ra(arrs);
	i++;
	return (i);
}

void	ft_min_rotate(t_arrs *arrs)
{
	int	i;

	i = 0;
	while (arrs->a[0] != arrs->linemin)
	{
		if (arrs->a[0] < arrs->mida && arrs->a[0] > arrs->mina)
			pb(arrs);
		else
			i = ft_ra_i(arrs, i);
	}
	while (arrs->a[arrs->lena - 1] != arrs->linemax)
		i = ft_ra_i(arrs, i);
	while (arrs->lena - i)
	{
		if (arrs->a[0] < arrs->mida && arrs->a[0] > arrs->mina)
			pb(arrs);
		else
			i = ft_ra_i(arrs, i);
	}
}

void	ft_max_rotate(t_arrs *arrs)
{
	int	i;

	i = 0;
	while (arrs->a[0] != arrs->linemin)
	{
		if (arrs->a[0] >= arrs->mida && arrs->a[0] < arrs->maxa)
			pb(arrs);
		else
			i = ft_ra_i(arrs, i);
	}
	while (arrs->a[arrs->lena - 1] != arrs->linemax)
		i = ft_ra_i(arrs, i);
	while (arrs->lena - i)
	{
		if (arrs->a[0] >= arrs->mida && arrs->a[0] < arrs->maxa)
			pb(arrs);
		else
			i = ft_ra_i(arrs, i);
	}
}

int	ft_rotate_line(t_arrs *arrs)
{
	int	i;

	i = 0;
	ft_min_rotate(arrs);
	ft_max_rotate(arrs);
	while (ft_cond_sort(arrs) != 0)
	{
		if (arrs->a[0] == arrs->maxa && arrs->a[1] == arrs->mina)
		{
			sa(arrs);
			break ;
		}
		if (arrs->a[1] == arrs->maxa && arrs->a[0] == arrs->mina)
			sa(arrs);
		else
			rra(arrs);
	}
	return (0);
}
