/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:42:24 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/14 23:30:35 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_b_a(t_arrs *arrs)
{
	while (arrs->lenb > 0)
	{
		arrs->minal = ft_mina(arrs);
		arrs->maxal = ft_maxa(arrs);
		if (arrs->b[0] < arrs->a[0])
		{
			if (arrs->b[0] < arrs->minal && arrs->a[0] == arrs->minal)
				pa(arrs);
			else if (arrs->b[0] > arrs->a[arrs->lena - 1])
				pa(arrs);
			else if (arrs->b[0] > arrs->a[arrs->lena / 2])
				rra(arrs);
			else
				ra(arrs);
		}
		else if (arrs->b[0] > arrs->maxal && arrs->a[0] == arrs->minal)
			pa(arrs);
		else
			ra(arrs);
	}
}

int	ft_check_int(char *s)
{
	int	i;

	i = -1;
	if (ft_strlen(s) == 11 && s[0] == '-')
	{
		while (s[++i])
		{
			if (s[i] > "-2147483648"[i])
				return (0);
		}
	}
	else if (ft_strlen(s) == 10 && s[0] != '-')
	{
		while (s[++i])
			if (s[i] > "2147483647"[i])
				return (0);
	}
	else if (ft_strlen(s) > 10)
		return (0);
	return (1);
}

static	int	ft_cond_flag(t_arrs *arrs, int j, int flag)
{
	int	i;

	while (j <= arrs->lena - 1 && arrs->a[0] != arrs->maxal)
	{
		i = 0;
		while (i < flag)
		{
			if (arrs->a[i] < arrs->a[j])
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_cond_sort(t_arrs *arrs)
{
	int	i;
	int	j;
	int	flag;

	arrs->minal = ft_mina(arrs);
	arrs->maxal = ft_maxa(arrs);
	i = 0;
	while (i < arrs->lena - 1)
	{
		if (arrs->a[i] < arrs->a[i + 1] || ((arrs->a[i] == arrs->maxal)
				&& (arrs->a[i + 1] == arrs->minal)))
		{
			i++;
			if (arrs->a[i] == arrs->minal)
			{
				flag = i - 1;
				j = i + 1;
			}
		}
		else if (arrs->a[i] > arrs->a[i + 1])
			return (1);
	}
	ft_cond_flag(arrs, j, flag);
	return (0);
}

int	ft_sort5(t_arrs *arrs)
{
	if (ft_check_sort(arrs) != 0 || ft_cond_sort(arrs) != 0)
	{
		while (arrs->lena > 3)
			pb(arrs);
		if (ft_cond_sort(arrs) != 0)
			sa(arrs);
		ft_b_a(arrs);
		while (ft_check_sort(arrs) != 0)
		{
			if (ft_check_sort(arrs) == 1)
				ra(arrs);
			if (ft_check_sort(arrs) == -1)
				rra(arrs);
		}
	}
	return (0);
}
