/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:40:33 by dswarm            #+#    #+#             */
/*   Updated: 2021/07/11 20:05:16 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr (char *str, int c);
char	*ft_strdup (const char *s1);
void	ft_free(char **line);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strjoin2(char *s1, char *s2, int len);
void	*ft_calloc(size_t count, size_t n);

#endif
