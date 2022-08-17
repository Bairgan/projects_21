/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 22:15:06 by dswarm            #+#    #+#             */
/*   Updated: 2021/05/13 22:40:01 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*str;

	str = NULL;
	if (*lst != NULL)
	{
		str = *lst;
		*lst = new;
		new->next = str;
	}
	else
	{
		*lst = new;
		new->next = NULL;
	}
}
