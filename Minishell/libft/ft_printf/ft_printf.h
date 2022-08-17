/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:56:29 by mclotild          #+#    #+#             */
/*   Updated: 2021/10/09 12:20:38 by mclotild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	g_res;
	int	g_width;
	int	g_dot;
	int	g_minus;
	int	g_zero;
}				t_flags;

void	ft_putchar(char c, t_flags *flags);
void	ft_putstr(char *str, t_flags *flags);
int		ft_strlen(char *str);
void	ft_cleanflags(t_flags *flags);
void	ft_dot(const char *str, t_flags *flags);
int		ft_zero(const char *str, t_flags *flags);
int		ft_width(t_flags *flags, const char *str);
int		ft_star2(t_flags *flags, const char *str, va_list ap);
int		ft_star(t_flags *flags, va_list ap);
int		ft_itoa_add(int len, unsigned long t, int b);
char	*ft_itoa_p(unsigned long nbr, int base);
void	ft_format_left(char *str, int len, t_flags *flags, int minus);
void	ft_format_right_help(int minus, t_flags *flags, int len);
void	ft_format_right(char *str, int len, t_flags *flags, int minus);
void	ft_printf_d(long nbr, t_flags *flags);
void	ft_swrite(t_flags *flags, char *str2);
void	ft_printf_s_add2(t_flags *flags);
void	ft_printf_s_add(t_flags *flags, char *str);
void	ft_printf_s(char *str, t_flags *flags);
void	ft_pprint_left(t_flags *flags, char *str, int len);
void	ft_pprint_right(t_flags *flags, char *str, int len);
void	ft_printf_p(int *nbr, t_flags *flags);
void	ft_uprint_right(t_flags *flags, char *str, int len, int nbr);
void	ft_uprint_left(t_flags *flags, char *str, int len, int nbr);
int		ft_dlina_nbr(int nbr);
void	ft_printf_u(unsigned long nbr, t_flags *flags);
void	ft_cprint_right(t_flags *flags, int c);
void	ft_cprint_left(t_flags *flags, int c);
void	ft_printf_c(int c, t_flags *flags);
void	ft_printf_x(unsigned long nbr, t_flags *flags);
void	ft_printf_x_up(unsigned long nbr, t_flags *flags);
void	ft_argument(t_flags *flags, va_list ap, const char *str);
void	add_pars(t_flags *flags);
void	pars(const char *str, va_list ap, t_flags *flags);
int		ft_printf(const char *str, ...);

#endif
