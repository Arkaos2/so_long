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
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	y1 = (game->py + 31) / 32;
	y0 = game->py / 32;
	x1 = (game->px + 31) / 32;
	x0 = game->px / 32;
	collect_at(game, x0, y0);
	collect_at(game, x1, y0);
	collect_at(game, x0, y1);
	collect_at(game, x1, y1);
}

int	all_collected(t_game *game)
{
	if (game->collectibles == 0)
		return (1);
	else
		return (0);
}

int	killed(t_game *game)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	y1 = (game->py + 31) / 32;
	y0 = game->py / 32;
	x1 = (game->px + 31) / 32;
	x0 = game->px / 32;

	if (game->map[y0][x0] == 'M' || game->map[y0][x1] == 'M' ||
		game->map[y1][x0] == 'M' || game->map[y1][x1] == 'M')
	{
		ft_printf("Tes Mort Frérot\n");
		return (1);
	}
	return (0);
}
