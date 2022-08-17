/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:55:48 by mclotild          #+#    #+#             */
/*   Updated: 2021/09/29 15:28:38 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_clean(int get, char **line, char **cache);
void	*ft_realloc(char *old, int size);
char	*ft_read_line(int fd, char **line, char **cache);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int ch);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
