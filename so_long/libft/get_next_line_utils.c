/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:37:09 by dswarm            #+#    #+#             */
/*   Updated: 2021/12/25 23:15:48 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *s1, char *s2, int len)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = ft_calloc((ft_strlen(s1) + len + 2), 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	c = 0;
	while (s2[c] != '\0' && (int )c < len)
		str[i++] = s2[c++];
	ft_free(&s1);
	str[i] = '\0';
	return (str);
}
