/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:04:51 by dswarm            #+#    #+#             */
/*   Updated: 2022/02/03 22:11:33 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_num(char **argv)
{
	int i;
	int j;

	j = 0;
	while (argv[++j])
	{
		i = -1;
		while (argv[j][++i])
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
	}
	return (1);
}

int ft_parsing(int argc, char **argv, t_ph *p)
{
	if (check_num(argv))
	{
		p->a.num_ph = ft_atoi(argv[1]);
		p->a.die = ft_atoi(argv[2]);
		p->a.eat = ft_atoi(argv[3]);
		p->a.sleep = ft_atoi(argv[4]);
		p->a.m_eat = -1;
		if (argc == 6)
			p->a.m_eat = ft_atoi(argv[5]);
		if (p->a.num_ph <= 0 || p->a.die <= 0 || p->a.eat <= 0 \
			|| p->a.sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_ph		p;

	if (argc != 5 && argc != 6)
	{
		printf("error\n");
		return (1);
	}

	if (!(parse_args(argc, argv, &p)))
		return (ft_exit("Invalid Arguments\n"));
	p.ph = malloc(sizeof(t_philo) * p.a.num_ph);
	if (!p.ph)
		return (ft_exit("Malloc returned NULL\n"));
	if (!initialize(&p) || !threading(&p))
	{
		free(p.ph);
		return (0);
	}
	stop(&p);
}
