/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:02:23 by mamerlin          #+#    #+#             */
/*   Updated: 2024/03/09 20:00:02 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RES 64

# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "structures.h"
# include "mlx/mlx.h"

int		check_p_letter(t_map *map, t_flag *flag);
char	**matrice(t_map *map);
int		dim_matrix(t_map *map);
int		set_game(t_game *game, char *path);
void	set_flag(t_flag *flag);
void	init_image(t_game *g);
void	print_map(t_game g);
void	*get_tile(t_game game, char c);
int		key_hook(int key, t_game *game);
int		ft_quit(t_game *game);
int		move_w(t_game *g);
int		move_s(t_game *g);
int		move_a(t_game *g);
int		move_d(t_game *g);
void	put_str(t_game *g);
int		ft_numlen(long int i);
char	*ft_itoa(int n);
#endif
