/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:44:47 by saibelab          #+#    #+#             */
/*   Updated: 2025/09/25 14:54:44 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

int	end_exit(t_game *game)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	y1 = (game->py + 31) / 32;
	y0 = game->py / 32;
	x1 = (game->px + 31) / 32;
	x0 = game->px / 32;
	if (game->map[y0][x0] == 'E'
		|| game->map[y0][x1] == 'E'
		|| game->map[y1][x0] == 'E'
		|| game->map[y1][x1] == 'E')
		return (1);
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
