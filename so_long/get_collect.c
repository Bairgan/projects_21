/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:34:21 by dswarm            #+#    #+#             */
/*   Updated: 2022/01/24 19:35:06 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_collect2(t_map *game, int i, char **s)
{
	while (i < 2)
	{
		game->collect[i] = (t_pic *)ft_calloc(sizeof(t_pic), 1);
		if (!game->collect[i])
			ft_exit(game);
		game->collect[i]->img = mlx_xpm_file_to_image(game->mlx, s[i],
				&game->collect[i]->w, &game->collect[i]->h);
		if (game->collect[i]->img == NULL)
			ft_exit(game);
		i++;
	}
}

void	get_collect(t_map *game)
{
	int		i;
	char	**s;

	s = ft_calloc(sizeof(char *), 3);
	s[0] = ft_strdup("img/mushroom.xpm");
	if (s[0] == NULL)
		ft_exit(game);
	s[1] = ft_strdup("img/mushroom1.xpm");
	if (s[1] == NULL)
		ft_exit(game);
	i = 0;
	get_collect2(game, i, s);
	i = 0;
	while (i < 2)
		free(s[i++]);
	free(s);
}
