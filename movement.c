/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:57:36 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/09 18:18:28 by mamerlin         ###   ########.fr       */
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
	if (key == 53)
		ft_quit(game);
	else if (key == 13)
		game->moves = move_w(game);
	else if (key == 1)
		game->moves = move_s(game);
	else if (key == 0)
		game->moves = move_a(game);
	else if (key == 2)
		game->moves = move_d(game);
	print_map(*game);
	return (0);
}
int	move_w(t_game *g)
{
	
}
