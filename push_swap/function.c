/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:51:28 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/15 23:23:20 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_maxa(t_arrs *arrs)
{
	int	i;
	int	max;

	i = 0;
	max = -2147483648;
	while (i < arrs->lena)
	{
		if (arrs->a[i] > max)
			max = arrs->a[i];
		i++;
	}
	return (max);
}

int	ft_mina(t_arrs *arrs)
{
	int	i;
	int	min;

	i = 0;
	min = 2147483647;
	while (arrs->lena > i)
	{
		if (arrs->a[i] < min)
			min = arrs->a[i];
		i++;
	}
	return (min);
}

int	ft_sortc(t_arrs *arrs)
{
	int	i;
	int	j;
	int	temp;

	arrs->lenc = arrs->lena;
	i = -1;
	while (++i < arrs->lenc)
		arrs->c[i] = arrs->a[i];
	j = 0;
	while (j++ < arrs->lenc)
	{
		i = 0;
		while (i < (arrs->lenc - j))
		{
			if (arrs->c[i] > arrs->c[i + 1])
			{
				temp = arrs->c[i];
				arrs->c[i] = arrs->c[i + 1];
				arrs->c[i + 1] = temp;
			}
			i++;
		}
	}
	arrs->mida = arrs->c[arrs->lenc / 2];
	return (0);
}

int	ft_check_error(int argc, char **argv, t_arrs *arrs)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	while (i < argc)
	{
		j = -1;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][++j])
			if ((ft_isdigit(argv[i][j]) == 0))
				return (1);
		if (!ft_check_int(argv[i++]))
			return (1);
		j = -1;
		while (++j < arrs->lena)
		{
			n = -1;
			while (++n < arrs->lena)
				if (arrs->a[j] == arrs->a[n] && j != n)
					return (1);
		}
	}
	return (0);
}

int	ft_check_sort(t_arrs *arrs)
{
	int	i;

	i = 0;
	while (i < arrs->lena - 1)
	{
		if (arrs->a[i] > arrs->a[i + 1])
		{
			if (i >= arrs->lena / 2)
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
