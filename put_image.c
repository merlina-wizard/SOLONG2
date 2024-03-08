/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:06:06 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/08 20:52:12 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_game *g)
{
	int	daje;

	daje = 64;
	g->map.wall.img
		= mlx_xpm_file_to_image(g->mlx, "xpm/lava.xpm", &daje, &daje);
	g->map.bg.img
		= mlx_xpm_file_to_image(g->mlx, "xpm/background.xpm", &daje, &daje);
	g->map.player[0].img
		= mlx_xpm_file_to_image(g->mlx, "xpm/Rogue.xpm", &daje, &daje);
	g->map.exit.img
		= mlx_xpm_file_to_image(g->mlx, "xpm/exit.xpm", &daje, &daje);
	g->map.coin.img
		= mlx_xpm_file_to_image(g->mlx, "xpm/white.xpm", &daje, &daje);
}

void	print_map(t_game g)
{
	int	x;
	int	y;

	x = 0;
	while (x < g.map.len)
	{
		y = 0;
		while (y < g.map.h)
		{
			mlx_put_image_to_window(g.mlx, g.win,
				get_tile(g, g.map.mat[y][x]), x * 64, y * 64);
			y++;
		}
		x++;
	}
}

void	*get_tile(t_game game, char c)
{
	if (c == '1')
		return (game.map.wall.img);
	if (c == '0')
		return (game.map.bg.img);
	if (c == 'E')
		return (game.map.exit.img);
	if (c == 'P')
		return (game.map.player[0].img);
	if (c == 'C')
		return (game.map.coin.img);
	if (c == 'N')
		return (game.map.enemy.img);
	else
		return (NULL);
}
