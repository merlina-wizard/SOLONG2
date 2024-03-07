/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:57:00 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/07 19:42:03 by mamerlin         ###   ########.fr       */
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

int	set_game(t_game *game, char *path)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.h = 0;
	game->map.path = path;
	game->map.len = 0;
	game->map.mat = NULL;
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

void	set_flag(t_flag *flag)
{
	flag->c = 0;
	flag->e = 0;
	flag->p = 0;
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
	map -> len = ft_strlen(line) - 1;
	while (line)
	{
		to_free = line;
		if (ft_strlen(line) - 1 == (size_t)map->len)
		{
			map -> h++;
			line = get_next_line(fd);
			free(to_free);
		}
		else
			return (-2);
		printf("h : %i\n", map->h);
	}
	free(line);
	close(fd);
	return (0);
}

char	**matrice(t_map *map)
{
	int		i;
	int		fd;
	char	**matrix;

	i = -1;
	fd = open(map -> path, O_RDONLY);
	matrix = (char **)malloc(sizeof(char *) * (map -> h) + 1);
	if (!matrix)
		return (NULL);
	matrix[(map -> h)] = NULL;
	while (++i < map -> h)
		matrix[i] = get_next_line(fd);
	close(fd);
	map->mat = matrix;
	return (matrix);
}

static int	counter_letter(char **map, int x, int y, t_flag *flag)
{
	if (map[y][x] == 'E')
		flag->e++;
	else if (map[y][x] == 'P')
		flag->p++;
	else if (map[y][x] == 'C')
		flag->c++;
	return (1);
}

int	check_p_letter(t_map *map, t_flag *flag)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->len)
	{
		y = 0;
		while (y < map->h)
		{
			if ((x == 0 || x == map->len || y == 0
					|| y == map->h) && (map->mat[y][x] != '1'))
				return (-1);
			if (!(map->mat[y][x] != 'C' || map->mat[y][x] != 'E'
				|| map->mat[y][x] != 'P' ||
					map->mat[y][x] != '1' || map->mat[y][x] != '0'))
				return (-1);
			counter_letter(map->mat, x, y, flag);
			y++;
		}
		x++;
	}
	if (flag->e != 1 || flag->p != 1 || flag->c < 1)
		return (-1);
	return (1);
}
