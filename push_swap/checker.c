/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:58:25 by dswarm            #+#    #+#             */
/*   Updated: 2021/10/15 23:28:22 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	commands_detect(char *line, t_arrs *arrs)
{
	if (ft_strcmp(line, "sa") == 0)
		sa_b(arrs);
	else if (ft_strcmp(line, "sb") == 0)
		sb_b(arrs);
	else if (ft_strcmp(line, "ss") == 0)
		ss_b(arrs);
	else if (ft_strcmp(line, "pa") == 0)
		pa_b(arrs);
	else if (ft_strcmp(line, "pb") == 0)
		pb_b(arrs);
	else if (ft_strcmp(line, "ra") == 0)
		ra_b(arrs);
	else if (ft_strcmp(line, "rb") == 0)
		rb_b(arrs);
	else if (ft_strcmp(line, "rr") == 0)
		rr_b(arrs);
	else
		commands_detect2(line, arrs);
}

void	read_commands(t_arrs *arrs)
{
	char	*line;

	while (get_next_line(&line))
	{
		commands_detect (line, arrs);
		free (line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_arrs	*arrs;

	arrs = ft_transform(argc, argv);
	if (ft_check_error(argc, argv, arrs))
	{
		write(2, "Error\n", 7);
	}
	else if (argc > 1)
	{
		read_commands(arrs);
		if (ft_check_sort(arrs) == 0 && arrs->lenb == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free(arrs);
	arrs = NULL;
	return (0);
}
