/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 22:36:44 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/14 23:29:15 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arrs	*ft_transform(int argc, char **argv)
{
	t_arrs	*arrs;
	int		i;

	arrs = NULL;
	arrs = malloc(sizeof(t_arrs));
	i = 0;
	arrs->argc = argc;
	while (argc-- > 1)
	{
		arrs->a[i] = ft_atoi(argv[i + 1]);
		arrs->b[i] = 0;
		i++;
	}
	arrs->lena = arrs->argc - 1;
	arrs->lenb = 0;
	arrs->maxa = ft_maxa(arrs);
	arrs->mina = ft_mina(arrs);
	ft_sortc(arrs);
	return (arrs);
}

int	main(int argc, char **argv)
{
	t_arrs	*arrs;

	arrs = ft_transform(argc, argv);
	if (ft_check_error(argc, argv, arrs))
		write(1, "Error\n", 6);
	else if (argc != 1 && ft_check_sort(arrs) != 0)
	{
		if (arrs->lena <= 5)
			ft_sort5(arrs);
		else
			ft_sort_global(arrs);
		while (arrs->mina != arrs->a[0])
		{
			if (arrs->a[0] > arrs->mida)
				ra(arrs);
			else
				rra(arrs);
		}
	}
	free(arrs);
	arrs = NULL;
	return (0);
}
