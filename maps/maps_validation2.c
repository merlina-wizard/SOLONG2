/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_validation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:40:33 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/12 16:40:10 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_mat(t_game g)
{
	char	**copy;
	int		y;

	y = 0;
	copy = (char **)malloc(sizeof(char *) * g.map.h + 1);
	if (!copy)
		return (-1);
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
	int		count;

	mat = g->map.copy[y][x];
	g->map.copy[y][x] = '1';
	if (mat[y + 1][x] != '1')
		blood_fill(g, y + 1, x);
	if (mat[y - 1][x] != '1')
		blood_fill(g, y - 1, x);
	if (mat[y][x + 1] != '1')
		blood_fill(g, y, x + 1);
	if (mat[y][x - 1] != '1')
		blood_fill(g, y, x - 1);
}

int	check_blood(t_game g)
{
	int	y;

	y = 0;
	blood_fill(&g, g.map.player->posx, g.map.player->posy);
	while(y < g.map.h)
	{
		ft_strrchr(g.map.copy[y]);
		y++;
	}
}
