/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_validation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:40:33 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/12 17:55:50 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_mat(t_game g)
{
	char	**copy;
	int		y;

	y = 0;
	copy = (char **)malloc(sizeof(char *) * g.map.h + 1);
	if (!copy)
		return (NULL);
	copy[g.map.h] = '\0';
	while (y < g.map.h)
	{
		ft_strdup(g.map.mat[y]);
		y++;
	}
	return (copy);
}

void	blood_fill(t_game *g, int x, int y)
{
	char	**mat;

	mat = g->map.copy;
	g->map.copy[y][x] = '1';
	if (mat[y + 1][x] != '1' && mat[y + 1][x] != 'N')
		blood_fill(g, y + 1, x);
	if (mat[y - 1][x] != '1' && mat[y - 1][x] != 'N')
		blood_fill(g, y - 1, x);
	if (mat[y][x + 1] != '1' && mat[y][x + 1] != 'N')
		blood_fill(g, y, x + 1);
	if (mat[y][x - 1] != '1' && mat[y][x - 1] != 'N')
		blood_fill(g, y, x - 1);
}

int	check_blood(t_game g)
{
	int	y;

	y = 0;
	g.map.copy = copy_mat(g);
	blood_fill(&g, g.map.player->posx, g.map.player->posy);
	while (y < g.map.h)
	{
		if (ft_strchr(g.map.copy[y], 'C') != 0)
			return (-1);
		if (ft_strchr(g.map.copy[y], 'E') != 0)
			return (-1);
		y++;
	}
	return (1);
}
