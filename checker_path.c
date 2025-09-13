/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:56:12 by saibelab          #+#    #+#             */
/*   Updated: 2025/09/13 16:56:12 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int y, int x, int nb_lines)
{
	int	line_len;

	if (!map || y < 0 || y >= nb_lines)
		return ;
	line_len = ft_strlen(map[y]);
	if (x < 0 || x >= line_len)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'M')
		return ;
	map[y][x] = 'V';
	flood_fill(map, y + 1, x, nb_lines);
	flood_fill(map, y - 1, x, nb_lines);
	flood_fill(map, y, x + 1, nb_lines);
	flood_fill(map, y, x - 1, nb_lines);
}

char	**map_parse(t_game *game, int nb_lines)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = gc_malloc(game->gc, sizeof(char *) * (nb_lines + 1));
	if (!map_copy)
		return (NULL);
	while (i < nb_lines)
	{
		map_copy[i] = gc_strdup(game->gc, game->map[i]);
		if (!map_copy[i])
			return (NULL);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	find_player(t_game *game, char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'P')
			{
				game->y = y;
				game->x = x;
				game->px = x * 32;
				game->py = y * 32;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_path(t_game *game, int nb_lines)
{
	char	**map_copy;
	int		y;
	int		x;

	map_copy = map_parse(game, nb_lines);
	if (!map_copy)
		return (0);
	find_player(game, map_copy);
	flood_fill(map_copy, game->y, game->x, nb_lines);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
