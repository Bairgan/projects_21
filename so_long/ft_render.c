/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:52:41 by dswarm            #+#    #+#             */
/*   Updated: 2022/01/25 16:04:56 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	window_img(t_map *game)
{
	game->pic = malloc(sizeof(t_pic));
	game->pic->img = mlx_new_image(game->mlx, 100, 100);
	game->pic->addr = mlx_get_data_addr(game->pic->img, &game->pic->bpp,
			&game->pic->len_line, &game->pic->endian);
	mlx_put_image_to_window(game->mlx, game->window, game->pic->img, 0, 0);
	return (0);
}

void	mlx_render(t_map *game, int y, int x)
{
	while (++x < game->w_map)
	{
		if (game->map[y][x] == '0')
			mlx_put_image_to_window(game->mlx, game->window,
				game->pic->img, x * 50, y * 50);
		if (game->map[y][x] == 'P')
			mlx_put_image_to_window(game->mlx, game->window,
				game->pl->img, x * 50, y * 50);
		if (game->map[y][x] == '1')
			mlx_put_image_to_window(game->mlx, game->window,
				game->wall->img, x * 50, y * 50);
		if (game->map[y][x] == 'C')
			mlx_put_image_to_window(game->mlx, game->window,
				game->collect[game->s]->img, x * 50, y * 50);
		if (game->map[y][x] == 'E' && game->count_c != 0)
			mlx_put_image_to_window(game->mlx, game->window,
				game->exit->img, x * 50, y * 50);
		if (game->map[y][x] == 'E' && game->count_c == 0)
			mlx_put_image_to_window(game->mlx, game->window,
				game->exit2->img, x * 50, y * 50);
		if (game->map[y][x] == 'D')
			mlx_put_image_to_window(game->mlx, game->window,
				game->enemy->img, x * 50, y * 50);
	}
}

static void	string_put(t_map *game, char *str)
{
	mlx_string_put(game->mlx, game->window, 10, 10, 0x00FF00, "MOVES");
	mlx_string_put(game->mlx, game->window, 100, 10, 0x00FF00, str);
	free (str);
}

int	ft_render(t_map *game)
{
	int		x;
	int		y;
	char	*str;

	y = -1;
	if (game->i < 30)
		game->s = 0;
	else
		game->s = 1;
	window_img(game);
	while (++y < game->h_map)
	{
		x = -1;
		mlx_render(game, y, x);
	}
	game->i++;
	if (game->i > 60)
		game->i = 0;
	str = ft_itoa(game->count_movies);
	if (!str)
		ft_exit(game);
	string_put(game, str);
	clear_img(&game->pic, game);
	return (0);
}

void	ft_mlx(t_map *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->w_map * 50,
			game->h_map * 50, "game");
	game->pl = malloc(sizeof(t_pic));
	game->pl->img = mlx_xpm_file_to_image(game->mlx, "img/fat.xpm",
			&game->pl->w, &game->pl->h);
	game->wall = malloc(sizeof(t_pic));
	game->wall->img = mlx_xpm_file_to_image(game->mlx, "img/wooden-crate.xpm",
			&game->wall->w, &game->wall->h);
	game->enemy = malloc(sizeof(t_pic));
	game->enemy->img = mlx_xpm_file_to_image(game->mlx, "img/enemy.xpm",
			&game->enemy->w, &game->enemy->h);
	game->exit = malloc(sizeof(t_pic));
	game->exit->img = mlx_xpm_file_to_image(game->mlx, "img/door.xpm",
			&game->exit->w, &game->exit->h);
	game->exit2 = malloc(sizeof(t_pic));
	game->exit2->img = mlx_xpm_file_to_image(game->mlx, "img/door2.xpm",
			&game->exit2->w, &game->exit2->h);
	game->collect = malloc(sizeof(t_pic));
	get_collect(game);
	mlx_hook(game->window, 2, 1L << 0, ft_key, game);
	mlx_hook(game->window, 17, 0L, &ft_exit, game);
	mlx_loop_hook(game->mlx, ft_render, game);
	mlx_loop(game->mlx);
}
