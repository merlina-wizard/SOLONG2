/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:57:36 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/08 21:15:26 by mamerlin         ###   ########.fr       */
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
	return (0);
}
