/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:57:00 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/11 20:42:14 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	return (1);
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

static int	counter_letter(t_map *map, int x, int y, t_flag *flag)
{
	if (map->mat[y][x] == 'E')
		flag->e++;
	else if (map->mat[y][x] == 'P')
	{
		flag->p++;
		map->player->posx = x;
		map->player->posy = y;
	}
	else if (map->mat[y][x] == 'C')
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
			counter_letter(map, x, y, flag);
			y++;
		}
		x++;
	}
	if (flag->e != 1 || flag->p != 1 || flag->c < 1)
		return (-1);
	return (1);
}

int	ft_argcheck(t_game g)
{
	int	i;

	i = ft_strlen(g.map.path);
	if (g.map.path[i - 1] != 'r'
		|| g.map.path[i - 2] != 'e' || g.map.path[i - 3] != 'b'
		|| g.map.path[i - 4] != '.')
		return (0);
	return (1);
}

/*int	blood_fill(t_game g, int x, int y)
{
	char	**mat;
	int		count;

	count = g.flag.c;
	mat = g.map.mat[y][x];
	if (mat[y][x] == 'C')
		count--;
	if (mat[y][x] == 'E')
		g.flag.e = 0;
	if (count == 0 && g.flag.e == 0)
		return (1);
	g.map.mat[y][x] = '1';

	else
	{
		if (mat[y + 1][x] != '1')
			blood_fill(g, y + 1, x);
		if (mat[y - 1][x] != '1')
			blood_fill(g, y - 1, x);
		if (mat[y][x + 1] != '1')
			blood_fill(g, y, x + 1);
		if (mat[y][x - 1] != '1')
			blood_fill(g, y, x - 1);
	}
	return (0);
}*/
