/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:59:21 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/14 23:28:10 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dadb(t_arrs *arrs)
{
	rr(arrs);
	arrs->arot--;
	arrs->brot--;
}

void	daub(t_arrs *arrs)
{
	ra(arrs);
	rrb(arrs);
	arrs->arot--;
	arrs->brot++;
}

void	uaub(t_arrs *arrs)
{
	rrr(arrs);
	arrs->arot++;
	arrs->brot++;
}

void	uadb(t_arrs *arrs)
{
	rra(arrs);
	rb(arrs);
	arrs->arot++;
	arrs->brot--;
}

void	da0b(t_arrs *arrs)
{
	ra(arrs);
	arrs->arot--;
}
