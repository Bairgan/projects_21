/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:57:10 by dswarm            #+#    #+#             */
/*   Updated: 2022/01/25 15:57:35 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *str, size_t n);
int		ft_isalnum(int ch);
void	*ft_memset(void *str, int i, size_t len);
int		ft_isalpha(int ch);
int		ft_isascii(int ch);
int		ft_isdigit(int ch);
int		ft_isprint(int c);
void	*ft_memccpy(void *dest, const void *source, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *source, size_t n);
void	*ft_memmove(void *dest, const void *source, size_t n);
void	*ft_memset(void *str, int i, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlen(const char *str);
int		ft_tolower(int i);
int		ft_toupper(int i);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

char	*get_next_line(int fd);
char	*ft_strjoin2(char *s1, char *s2, int len);
int		ft_index(char *str, char c);
char	*get_line(char **rem);
void	ft_free(char **line);
void	join(char *buf, char **line, char **rem, int fd);

#endif
