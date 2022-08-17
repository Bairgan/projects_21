/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:26:29 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/15 23:15:21 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra_b(t_arrs *arrs)
{
	int	temp;
	int	i;

	i = 0;
	temp = arrs->a[0];
	while (i < arrs->lena - 1)
	{
		arrs->a[i] = arrs->a[i + 1];
		i++;
	}
	arrs->a[arrs->lena - 1] = temp;
	return (0);
}

int	rb_b(t_arrs *arrs)
{
	int	temp;
	int	i;

	i = 0;
	temp = arrs->b[0];
	while (i < arrs->lenb - 1)
	{
		arrs->b[i] = arrs->b[i + 1];
		i++;
	}
	arrs->b[arrs->lenb - 1] = temp;
	return (0);
}

int	rr_b(t_arrs *arrs)
{
	int	temp;
	int	i;

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
	return (0);
}

int	get_next_line(char **line)
{
	int		rd;
	int		i;
	char	ch;
	char	*buffer;

	rd = 0;
	i = 0;
	buffer = malloc(100000);
	*line = buffer;
	rd = read(0, &ch, 1);
	while (rd > 0 && ch != '\n')
	{
		buffer[i++] = ch;
		rd = read(0, &ch, 1);
	}
	buffer[i] = '\0';
	return (rd);
}
