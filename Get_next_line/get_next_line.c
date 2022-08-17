/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:42:57 by dswarm            #+#    #+#             */
/*   Updated: 2021/07/12 15:39:10 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*get_line(char **rem)
{
	char	*new_l;
	char	*tmp;

	new_l = ft_calloc(1, 1);
	if (*rem && ft_strlen(*rem) > 0)
	{
		if (ft_index(*rem, '\n') == -1)
		{
			ft_free(&new_l);
			new_l = ft_strdup(*rem);
			ft_free(rem);
		}
		else
		{
			new_l = ft_strjoin2(new_l, *rem, ft_index(*rem, '\n') + 1);
			tmp = *rem;
			*rem = ft_strdup(ft_strchr(*rem, '\n') + 1);
			ft_free(&tmp);
		}
	}
	return (new_l);
}

void	ft_free(char **line)
{
	if (!*line)
		return ;
	free(*line);
	*line = NULL;
}

void	join(char *buf, char **line, char **rem, int fd)
{
	int	b;

	b = 1;
	while (b && (!rem || ft_index(*line, '\n') == -1))
	{
		b = read(fd, buf, BUFFER_SIZE);
		buf[b] = '\0';
		if (!(ft_strchr(buf, '\n')) && b == BUFFER_SIZE)
			*line = ft_strjoin2(*line, buf, ft_strlen(buf));
		else if (!ft_strchr(buf, '\n') && b < BUFFER_SIZE)
		{
			*line = ft_strjoin2(*line, buf, ft_strlen(buf));
			break ;
		}
		else if (ft_strlen(buf) > 0)
		{
			*line = ft_strjoin2(*line, buf, (ft_index(buf, '\n') + 1));
			*rem = ft_strdup(ft_strchr(buf, '\n') + 1);
			break ;
		}
	}
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*rem = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = get_line(&rem);
	join(buf, &line, &rem, fd);
	if (rem && *rem == '\0')
		ft_free(&rem);
	if (!ft_strlen(rem) && !ft_strlen(line))
	{
		ft_free(&line);
		return (NULL);
	}
	return (line);
}
