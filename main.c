/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:02:11 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/07 19:15:27 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_game	game;
	t_flag	flag;

	(void) argc;
	set_flag(&flag);

	set_game(&game, argv[1]);
	dim_matrix(&game.map);
	matrice(&game.map);

	int i = 0;
	while (game.map.mat[i])
	{
		printf("%s", game.map.mat[i]);
		i++;
	}
	if (check_p_letter(&game.map, &flag) == 1)
		printf("YES\n");
	printf("arriva\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, game.map.len * RES, game.map.h * RES, "So_Long");
	mlx_loop(mlx);
}
