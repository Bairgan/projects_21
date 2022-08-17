#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putpercent(char format, va_list ap, int *len);
void	ft_string(char *str, int *len);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putstr(char *s, int *len);
void	ft_nbrun(unsigned int n, int *len);
void	ft_putx(unsigned int n, int a, int *len);
void	ft_putp(unsigned long long n, int a, int *len);

#endif
