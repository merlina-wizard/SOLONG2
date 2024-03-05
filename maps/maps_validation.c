/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:57:00 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/05 17:04:21 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//maps
//ottenere il matrix con get
//dimensione mappa
//stampare all interno
//validazione
//C P E
//Perimeto
//[]
//strada (flood fill)

int	set_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.h = 1;
	game->map.path = NULL;
	game->map.len = 0;
	game->mat = NULL;
	game->map.ncoin = 0;
	game->map.coin_coll = 0;
	game->map.movcoin = 0;
	game->nmove = 0;
	game->loop = 0;
	game->npath = 0;
	game->aux_rand = 0;
	game->map.nexit = 0;
	return (1);
}

//setta h e len e controlla []
int	dim_matrix(t_map *map)
{
	int		fd;
	char	*line;
	char	*to_free;

	fd = open(map -> path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	map -> len = ft_strlen(line);
	while (line)
	{
		to_free = line;
		if (ft_strlen(line) == map -> len)
		{
			map -> h++;
			line = get_next_line(fd);
			free(to_free);
		}
		else
			return (-2);
	}
	free(line);
	close(fd);
	return (0);
}

char	**matricie(t_map *map)
{
	int		i;
	int		fd;
	char	**matrix;

	i = 0;
	fd = open(map -> path, O_RDONLY);
	matrix = (char **)malloc(sizeof(char *) * (map -> h) + 1);
	if (!matrix)
		return (NULL);
	*matrix[(map -> h) + 1] = NULL;
	while (i++ < map -> h)
		matrix[i] = get_next_line(fd);
	close(fd);
	return (matrix);
}

//check matrice

