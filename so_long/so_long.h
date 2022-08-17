/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:47:50 by dswarm            #+#    #+#             */
/*   Updated: 2022/01/25 16:09:29 by dswarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_pic
{
	void	*img;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		len_line;
	int		endian;
}				t_pic;

typedef struct s_map
{
	char	**map;
	int		pl_mov;
	int		h_map;
	int		w_map;
	void	*mlx;
	void	*window;
	int		count_c;
	int		count_movies;
	int		c_pl;
	int		c_ex;
	int		en_cnt;
	int		s;
	int		i;
	int		f;
	int		e;
	int		j;
	t_pic	*pic;
	t_pic	**collect;
	t_pic	*pl;
	t_pic	*exit;
	t_pic	*wall;
	t_pic	*enemy;
	t_pic	*exit2;
}				t_map;

void	ft_key_up(t_map *game, int y, int x);
void	ft_key_down(t_map *game, int y, int x, int i);
void	ft_key_right(t_map *game, int y, int x, int i);
void	ft_key_left(t_map *game, int y, int x);
int		ft_exit(t_map *game);
int		window_img(t_map *game);
void	ft_free_long(t_map *game);
void	clear_img(t_pic **pic, t_map *game);
void	mov_player_up(t_map *game, int y, int x);
void	mov_player_down(t_map *game, int y, int x);
void	mov_player_right(t_map *game, int y, int x);
void	mov_player_left(t_map *game, int y, int x);
void	mlx_render(t_map *game, int y, int x);
int		ft_key(int key, t_map *game);
int		ft_render(t_map *game);
void	ft_mlx(t_map *game);
void	get_collect(t_map *game);
void	enemy_moves_down(t_map *game);
void	enemy_moves_up(t_map *game);
void	open_door(t_map *game);
void	clear_imgs(t_pic ***pic, t_map *game);

#endif
