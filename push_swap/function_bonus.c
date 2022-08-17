/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:41:53 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/15 23:28:44 by dswarm           ###   ########.fr       */
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

void	commands_detect2(char *line, t_arrs *arrs)
{
	if (ft_strcmp(line, "rra") == 0)
		rra_b(arrs);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb_b(arrs);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr_b(arrs);
	else
	{
		write(1, "Error\n", 7);
		exit(1);
	}
}
