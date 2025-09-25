/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:47:15 by saibelab          #+#    #+#             */
/*   Updated: 2025/09/13 16:47:15 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectible(t_game *game)
{
	int	i;
	int	j;
	int	collectible;

	i = 0;
	collectible = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	game->collectibles = collectible;
	return (collectible);
}

void	collect_at(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collectibles--;
	}
}

void	collect_if_present(t_game *game)
{
	int	center_x;
	int	center_y;
	int	margin;

	margin = 8;
	center_x = game->px + 12;
	center_y = game->py + 12;
	collect_in_range(game, center_x, center_y, margin);
}

void	collect_in_range(t_game *game, int center_x, int center_y, int margin)
{
	int	x;
	int	y;

	x = (center_x - margin) / 32;
	y = (center_y - margin) / 32;
	if (x >= 0 && y >= 0)
		collect_at(game, x, y);
	x = (center_x + margin) / 32;
	y = (center_y - margin) / 32;
	if (x < game->map_width && y >= 0)
		collect_at(game, x, y);
	x = (center_x - margin) / 32;
	y = (center_y + margin) / 32;
	if (x >= 0 && y < game->map_height)
		collect_at(game, x, y);
	x = (center_x + margin) / 32;
	y = (center_y + margin) / 32;
	if (x < game->map_width && y < game->map_height)
		collect_at(game, x, y);
}

int	all_collected(t_game *game)
{
	if (game->collectibles == 0)
		return (1);
	else
		return (0);
}
