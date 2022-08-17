/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:55:43 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 14:55:44 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(int get, char **line, char **cache)
{
	if ((*line && get < 0) || (*line && **line == 0 && get == 0))
	{
		free(*line);
		*line = NULL;
	}
	if (*cache && get == -1)
	{
		free(*cache);
		*cache = NULL;
	}
	return (*line);
}

void	*ft_realloc(char *old, int size)
{
	char	*new;
	int		i;

	new = malloc(size);
	if (!new)
		return (NULL);
	i = 0;
	while (old && i < size && old[i])
	{
		new[i] = old[i];
		i++;
	}
	new[i] = '\0';
	if (old)
		free(old);
	return (new);
}

char	*ft_read_line(int fd, char **line, char **cache)
{
	char	buf[BUFFER_SIZE + 1];
	char	*end;
	size_t	len;
	int		get;

	len = ft_strlen(*line) + 1;
	while (1)
	{
		get = read(fd, buf, BUFFER_SIZE);
		buf[get] = 0;
		if (get <= 0)
			return (ft_clean(get, line, cache));
		end = ft_strchr(buf, '\n');
		if (end)
			break ;
		len += get;
		*line = ft_realloc(*line, len);
		ft_strlcat(*line, buf, len);
	}
	len += end - buf + 1;
	*line = ft_realloc(*line, len);
	ft_strlcat(*line, buf, len);
	*cache = ft_substr(buf, end - buf + 1, BUFFER_SIZE);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*end;
	char		*start;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (cache)
	{
		end = ft_strchr(cache, '\n');
		if (end)
		{
			line = ft_substr(cache, 0, end - cache + 1);
			start = ft_substr(cache, end - cache + 1, BUFFER_SIZE);
			free (cache);
			cache = start;
			return (line);
		}
		line = cache;
		cache = NULL;
	}
	else
		line = ft_realloc(line, 1);
	return (ft_read_line(fd, &line, &cache));
}
