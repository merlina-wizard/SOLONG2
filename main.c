/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:02:11 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/08 21:06:40 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_flag	flag;
	int	i;

	i = 0;
	(void) argc;
	set_flag(&flag);
	set_game(&game, argv[1]);
	dim_matrix(&game.map);
	matrice(&game.map);
	while (game.map.mat[i])
	{
		printf("%s", game.map.mat[i]);
		i++;
	}
	if (check_p_letter(&game.map, &flag) == 1)
		printf("YES\n");
	printf("arriva\n");
	game.mlx = mlx_init();
	game.win
		= mlx_new_window(game.mlx,
			game.map.len * RES, game.map.h * RES, "So_Long");
	init_image(&game);
	print_map(game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
}
