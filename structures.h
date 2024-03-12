/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:52:24 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/12 16:04:52 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_flag
{
	int	c;
	int	e;
	int	p;
}				t_flag;

typedef struct s_tile
{
	void	*img;
	char	type;
	int		posx;
	int		posy;
}				t_tile;

typedef struct s_map
{
	int		t_h;
	int		t_w;
	char	**mat;
	char	**copy;
	char	*path;
	int		h;
	int		len;
	t_tile	player[4];
	t_tile	player_to_print;
	t_tile	exit;
	int		coin_coll;
	int		movcoin;
	t_tile	coin;
	t_tile	enemy[2];
	t_tile	enemy_to_print;
	t_tile	wall;
	t_tile	bg;
}				t_map;

typedef struct s_game
{
	t_flag	flag;
	void	*mlx;
	void	*win;
	t_map	map;
	int		w;
	int		h;
	int		nmoves;
	int		loop;
	int		aux_rand;
}				t_game;

#endif
