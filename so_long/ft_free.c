/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:01:13 by dswarm            #+#    #+#             */
/*   Updated: 2022/01/25 16:56:30 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_pointer(void **pointer)
{
	if (!(*pointer))
	{
		free(*pointer);
		*pointer = NULL;
	}
}

void	clear_img(t_pic **pic, t_map *game)
{
	if (*pic)
	{
		if ((*pic)->img && game->mlx)
			mlx_destroy_image(game->mlx, (*pic)->img);
		free(*pic);
		*pic = NULL;
	}
}

void	ft_free_long(t_map *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
	{
		if (game->map[i])
			free_pointer((void **)&game->map[i]);
	}
	clear_img(&game->exit, game);
	clear_img(&game->exit2, game);
	clear_img(&game->pic, game);
	clear_img(&game->wall, game);
	clear_img(&game->pl, game);
	clear_img(&game->enemy, game);
	clear_img(&game->collect[0], game);
	clear_img(&game->collect[1], game);
	if (game->mlx != NULL && game->window != NULL)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
	}
}

int	ft_exit(t_map *game)
{
	ft_free_long(game);
	exit (0);
	return (0);
}
