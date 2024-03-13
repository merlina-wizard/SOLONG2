/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:04:03 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/13 16:50:35 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_matrix(char **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (matrix[y][x] != NULL)
	{
		x = 0;
		while (matrix[y][x] != '\0')
		{
			free(matrix[y][x]);
			x++;
		}
		free(matrix[y][x]);
		y++;
	}
	free(matrix);
	return (1);
}
