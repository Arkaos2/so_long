/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:25:11 by saibelab          #+#    #+#             */
/*   Updated: 2025/08/29 18:59:26 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "libft/libft.h"
#include <fcntl.h>

typedef struct	s_game
{
	char **map;
}		t_game;

void	*ft_error(char *str);
void	count_elements_line(char *line, int *player, int *exit, int *collect);
void	free_map(t_game *game);

int		map_load(char *args, t_game *game);
int		count_lines(char *filename);
int		check_all(t_game *game, int nb);
int		check_elements(t_game *game);
int		check_length(t_game *game);
int		check_border(t_game *game, int nb);
int		check_char(t_game *game);




#endif
