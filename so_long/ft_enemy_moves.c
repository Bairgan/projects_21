/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:52:25 by dswarm            #+#    #+#             */
/*   Updated: 2022/01/25 16:07:59 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	death_player(t_map *game, int y, int x)
{
	if (game->f == 0)
	{
		if (game->map[y][x] == 'D' && game->map[y + 1][x] == 'P')
		{
			printf("game over\n");
			ft_exit(game);
		}
	}
	else
	{
		if (game->map[y][x] == 'D' && game->map[y - 1][x] == 'P')
		{
			printf("game over\n");
			ft_exit(game);
		}
	}
}

static void	space_death(t_map *game, int y, int x)
{
	if (game->f == 0)
	{
		game->j = 1;
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'D';
	}
	else
	{
		game->j = 1;
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'D';
	}
}

void	enemy_moves_down(t_map *game)
{
	int	x;
	int	y;

	y = -1;
	game->j = 0;
	while (++y < game->h_map && game->f == 0)
	{
		x = -1;
		while (++x < game->w_map)
		{
			if (game->map[y][x] == 'D' && game->map[y + 1][x] != '1')
			{
				death_player(game, y, x);
				space_death(game, y, x);
			}
			if (game->map[y][x] == 'D' && game->map[y + 1][x] == '1')
			{
				game->f = 1;
				break ;
			}
		}
		if (game->j == 1 || game->f == 1)
			break ;
	}
}

void	enemy_moves_up(t_map *game)
{
	int	x;
	int	y;

	game->j = 0;
	y = -1;
	while (++y < game->h_map && game->f == 1)
	{
		x = -1;
		while (++x < game->w_map)
		{
			if (game->map[y][x] == 'D' && game->map[y - 1][x] != '1')
			{
				death_player(game, y, x);
				space_death(game, y, x);
			}
			if (game->map[y][x] == 'D' && game->map[y - 1][x] == '1')
			{
				game->f = 0;
				break ;
			}
		}
		if (game->j == 1 || game->f == 0)
			break ;
	}
}
