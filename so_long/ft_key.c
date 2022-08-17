/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:14:37 by dswarm            #+#    #+#             */
/*   Updated: 2022/01/16 00:08:16 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_player_left(t_map *game, int y, int x)
{
	if (game->map[y][x - 1] == 'D')
	{
		printf("game over\n");
		ft_exit(game);
	}
	if (game->map[y][x - 1] == 'C')
		game->count_c--;
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'P';
	if (game->f == 0)
		enemy_moves_down(game);
	if (game-> f == 1)
		enemy_moves_up(game);
	game->pl_mov = 1;
}

void	ft_key_left(t_map *game, int y, int x)
{
	while (++x < game->w_map)
	{
		y = -1;
		while (++y < game->h_map)
		{
			if (game->map[y][x] == 'P' && game->map[y][x - 1] != '1')
			{
				if (game->map[y][x - 1] == 'E' && game->count_c == 0)
				{
					game->map[y][x] = '0';
					game->map[y][x - 1] = 'E';
					printf("game complete\n");
					ft_exit(game);
				}
				if (game->map[y][x - 1] == 'E' && game->count_c != 0)
				{
					game->count_movies--;
					break ;
				}
				mov_player_left(game, y, x);
			}
		}
	}
}

void	mov_player_up(t_map *game, int y, int x)
{
	if (game->map[y - 1][x] == 'D')
	{
		printf("game over\n");
		ft_exit(game);
	}
	if (game->map[y - 1][x] == 'C')
		game->count_c--;
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'P';
	if (game->f == 0)
		enemy_moves_down(game);
	if (game-> f == 1)
		enemy_moves_up(game);
	game->pl_mov = 1;
}

void	ft_key_up(t_map *game, int y, int x)
{
	while (++y < game->h_map)
	{
		x = -1;
		while (++x < game->w_map)
		{
			if ((game->map[y][x] == 'P') && (game->map[y - 1][x] != '1'))
			{
				if (game->map[y - 1][x] == 'E' && game->count_c == 0)
				{
					game->map[y][x] = '0';
					game->map[y - 1][x] = 'E';
					printf("game complete\n");
					ft_exit(game);
				}
				if (game->map[y - 1][x] == 'E' && game->count_c != 0)
				{
					game->count_movies--;
					break ;
				}
				mov_player_up(game, y, x);
			}
		}
	}
}

int	ft_key(int key, t_map *game)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	x = -1;
	y = -1;
	game->count_movies++;
	game->pl_mov = 0;
	if (key == 53)
		ft_exit(game);
	if (key == 13)
		ft_key_up(game, y, x);
	if (key == 1)
		ft_key_down(game, y, x, i);
	if (key == 2)
		ft_key_right(game, y, x, i);
	if (key == 0)
		ft_key_left(game, y, x);
	if (game->pl_mov == 1)
		printf("movies = %d\n", game->count_movies);
	return (0);
}
