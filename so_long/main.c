/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:12:14 by dswarm            #+#    #+#             */
/*   Updated: 2022/01/25 16:57:01 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map2(t_map *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->h_map)
	{
		x = -1;
		while (++x < game->w_map)
		{
			if ((game->map[y][x] != '1' && game->map[y][x] != '0'
			&& game->map[y][x] != 'C' && game->map[y][x] != 'P'
			&& game->map[y][x] != 'E' && game->map[y][x] != 'D'))
				return (1);
			if (game->map[y][x] == 'P')
				game->c_pl++;
			if (game->map[y][x] == 'C')
				game->count_c++;
			if (game->map[y][x] == 'E')
				game->c_ex++;
			if (game->map[y][x] == 'D')
				game->en_cnt++;
		}
	}
	return (0);
}

int	check_map(t_map *game)
{
	int	x;

	x = -1;
	while (++x < game->h_map)
		if (game->map[x][0] != '1' || game->map[x][game->w_map - 1] != '1')
			return (1);
	x = -1;
	while (++x < game->w_map)
		if (game->map[0][x] != '1' || game->map[game->h_map - 1][x] != '1')
			return (1);
	x = -1;
	while (++x < game->h_map - 1)
		if (ft_strlen(game->map[x]) != ft_strlen(game->map[x + 1]))
			return (1);
	if (game->h_map == game->w_map || check_map2(game) == 1)
		return (1);
	if (game->c_pl != 1 || game->count_c == 0 || game->c_ex == 0)
		return (1);
	return (0);
}

int	count_h(char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

int	read_map(char **argv, t_map *game)
{
	int		fd;
	char	*line;
	int		i;

	i = count_h(argv);
	fd = open(argv[1], O_RDONLY);
	game->map = (char **)malloc(i * sizeof(char *));
	game->h_map = i;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map[i++] = line;
	}
	close(fd);
	game->w_map = ft_strlen(game->map[0]);
	if (check_map(game) == 1)
	{
		printf("Error maps\n");
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*game;

	if (argc != 2)
		return (0);
	game = (t_map *)malloc(sizeof(t_map));
	*game = (t_map){0};
	game->i = 0;
	game->f = 0;
	read_map(argv, game);
	ft_mlx(game);
	return (0);
}
