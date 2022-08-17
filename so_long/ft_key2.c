/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:20:58 by dswarm            #+#    #+#             */
/*   Updated: 2022/01/16 00:16:38 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_complete(t_map *game, int y, int x, int t)
{
	if (t == 0)
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'E';
		printf("game complete\n");
		ft_exit(game);
	}
	else
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'E';
		printf("game complete\n");
		ft_exit(game);
	}
}

void	mov_player_right(t_map *game, int y, int x)
{
	if (game->map[y][x + 1] == 'D')
	{
		printf("game over\n");
		ft_exit(game);
	}
	if (game->map[y][x + 1] == 'C')
		game->count_c--;
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'P';
	if (game->f == 0)
		enemy_moves_down(game);
	if (game-> f == 1)
		enemy_moves_up(game);
	game->pl_mov = 1;
}

void	ft_key_right(t_map *game, int y, int x, int i)
{
	int	t;

	t = 0;
	while (++x < game->w_map)
	{
		y = -1;
		while (++y < game->h_map)
		{
			if (game->map[y][x] == 'P' && game->map[y][x + 1] != '1')
			{
				i = 'P';
				if (game->map[y][x + 1] == 'E' && game->count_c == 0)
					game_complete(game, y, x, t);
				if (game->map[y][x + 1] == 'E' && game->count_c != 0)
				{
					game->count_movies--;
					break ;
				}
				mov_player_right(game, y, x);
			}
		}
		if (i == 'P')
			break ;
	}
}

void	mov_player_down(t_map *game, int y, int x)
{
	if (game->map[y + 1][x] == 'D')
	{
		printf("game over\n");
		ft_exit(game);
	}
	if (game->map[y + 1][x] == 'C')
		game->count_c--;
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'P';
	if (game->f == 0)
		enemy_moves_down(game);
	if (game-> f == 1)
		enemy_moves_up(game);
	game->pl_mov = 1;
}

void	ft_key_down(t_map *game, int y, int x, int i)
{
	int	t;

	t = 1;
	while (++y < game->h_map)
	{
		x = -1;
		while (++x < game->w_map)
		{
			if (game->map[y][x] == 'P' && game->map[y + 1][x] != '1')
			{
				i = 'P';
				if (game->map[y + 1][x] == 'E' && game->count_c == 0)
					game_complete(game, y, x, t);
				if (game->map[y + 1][x] == 'E' && game->count_c != 0)
				{
					game->count_movies--;
					break ;
				}
				mov_player_down(game, y, x);
			}
		}
		if (i == 'P')
			break ;
	}
}
