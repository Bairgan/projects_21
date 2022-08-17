/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:47:02 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/15 23:28:59 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct s_arrs
{
	int		a[1000];
	int		lena;
	int		argc;
	int		b[1000];
	int		c[1000];
	int		lenb;
	int		lenc;
	int		count;
	int		brot;
	int		arot;
	int		maxa;
	int		mina;
	int		mida;
	int		minal;
	int		maxal;
	int		ind;
	int		mlen;
	int		linemax;
	int		linemin;
}				t_arrs;

int		sa(t_arrs *arrs);
int		sb(t_arrs *arrs);
int		ss(t_arrs *arrs);
int		pb(t_arrs *arrs);
int		pa(t_arrs *arrs);
int		ra(t_arrs *arrs);
int		rb(t_arrs *arrs);
int		rr(t_arrs *arrs);
int		rra(t_arrs *arrs);
int		rrb(t_arrs *arrs);
int		rrr(t_arrs *arrs);
int		ft_atoi(const char *str);
t_arrs	*ft_transform(int argc, char **argv);
int		ft_check_sort(t_arrs *arrs);
int		ft_maxa(t_arrs *arrs);
int		ft_mina(t_arrs *arrs);
int		ft_sortc(t_arrs *arrs);
int		ft_check_error(int argc, char **argv, t_arrs *arrs);
int		ft_isdigit(int c);
int		ft_check_int(char *s);
size_t	ft_strlen(const char *str);
int		ft_cond_sort(t_arrs *arrs);
int		ft_sort5(t_arrs *arrs);
void	ft_b_a(t_arrs *arrs);
int		ft_sort_global(t_arrs *arrs);
void	ft_find_line(t_arrs *arrs);
int		ft_push_global(t_arrs *arrs);
void	ft_min_rotate(t_arrs *arrs);
void	ft_max_rotate(t_arrs *arrs);
int		ft_rotate_line(t_arrs *arrs);
void	ft_push_a(t_arrs *arrs);
int		ft_rotate(t_arrs *arrs);
void	choose_opt(t_arrs *arrs, int i, int j, int *min);
void	choose_opt1(t_arrs *arrs, int i, int j, int *min);
void	ft_rotater(t_arrs *arrs);
void	dadb(t_arrs *arrs);
void	daub(t_arrs *arrs);
void	uaub(t_arrs *arrs);
void	uadb(t_arrs *arrs);
void	da0b(t_arrs *arrs);
int		get_next_line(char **line);
int		sa_b(t_arrs *arrs);
int		sb_b(t_arrs *arrs);
int		ss_b(t_arrs *arrs);
int		pb_b(t_arrs *arrs);
int		pa_b(t_arrs *arrs);
int		ra_b(t_arrs *arrs);
int		rb_b(t_arrs *arrs);
int		rr_b(t_arrs *arrs);
int		rra_b(t_arrs *arrs);
int		rrb_b(t_arrs *arrs);
int		rrr_b(t_arrs *arrs);
void	read_commands(t_arrs *arrs);
void	commands_detect(char *line, t_arrs *arrs);
void	commands_detect2(char *line, t_arrs *arrs);
int		ft_strcmp(const char *s1, const char *s2);

#endif
