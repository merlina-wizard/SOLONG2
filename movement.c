/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:57:36 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/12 13:04:31 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//hook wasd e esc

#include "so_long.h"

int	ft_quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	key_hook(int key, t_game *game)
{
	if (key == 65307)
		ft_quit(game);
	else if (key == 119)
		game->nmoves += move_w(game);
	else if (key == 115)
		game->nmoves += move_s(game);
	else if (key == 97)
		game->nmoves += move_a(game);
	else if (key == 100)
		game->nmoves += move_d(game);
	print_map(*game);
	return (0);
}

int	move_w(t_game *g)
{
	int	y;
	int	x;

	y = (g->map.player->posy);
	x = g->map.player->posx;
	if (g->map.mat[y - 1][x] != '1' && check_path(g, (y - 1), x))
	{
		g->map.mat[y][x] = '0';
		y = (g->map.player->posy - 1);
		g->map.mat[y][x] = 'P';
		g->map.player->posy = y;
		g->map.player_to_print = g->map.player[1];
		return (1);
	}
	return (0);
}

int	move_s(t_game *g)
{
	int	y;
	int	x;

	y = (g->map.player->posy);
	x = g->map.player->posx;
	if (g->map.mat[y + 1][x] != '1' && check_path(g, y + 1, x))
	{
		g->map.mat[y][x] = '0';
		y = (g->map.player->posy + 1);
		g->map.mat[y][x] = 'P';
		g->map.player->posy = y;
		g->map.player_to_print = g->map.player[0];
		return (1);
	}
	return (0);
}

int	move_a(t_game *g)
{
	int	y;
	int	x;

	y = g->map.player->posy;
	x = g->map.player->posx;
	if (g->map.mat[y][x - 1] != '1' && check_path(g, y, x - 1))
	{
		g->map.mat[y][x] = '0';
		x = (g->map.player->posx - 1);
		g->map.mat[y][x] = 'P';
		g->map.player->posx = x;
		g->map.player_to_print = g->map.player[3];
		return (1);
	}
	return (0);
}

int	move_d(t_game *g)
{
	int	y;
	int	x;

	y = g->map.player->posy;
	x = g->map.player->posx;
	if (g->map.mat[y][x + 1] != '1' && check_path(g, y, x + 1))
	{
		g->map.mat[y][x] = '0';
		x = (g->map.player->posx + 1);
		g->map.mat[y][x] = 'P';
		g->map.player->posx = x;
		g->map.player_to_print = g->map.player[2];
		return (1);
	}
	return (0);
}

int	check_path(t_game *g, int y, int x)
{
	char	**mat;

	mat = g->map.mat;
	if (mat[y][x] == 'N')
		ft_quit(g);
	else if (mat[y][x] == 'E' && g->flag.c == 0)
		ft_quit(g);
	return (1);
}
