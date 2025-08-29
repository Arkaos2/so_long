/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:26:04 by saibelab          #+#    #+#             */
/*   Updated: 2025/08/29 18:58:42 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_elements_line(char *line, int *player, int *exit, int *collect)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'P')
			(*player)++;
		else if (line[j] == 'E')
			(*exit)++;
		else if (line[j] == 'C')
			(*collect)++;
		j++;
	}
}

int	check_elements(t_game *game)
{
	int	i;
	int	player;
	int	exit;
	int	collect;

	i = 0;
	player = 0;
	exit = 0;
	collect = 0;
	while (game->map[i])
	{
		count_elements_line(game->map[i], &player, &exit, &collect);
		i++;
	}
	if (player == 1 && exit && collect)
		return (1);
	else
		return (0);
}

int	check_length(t_game *game)
{
	size_t	len;
	size_t	current;
	int		i;

	i = 0;
	len = ft_strlen(game->map[0]);
	if (game->map[0][len - 1] == '\n')
		len--;
	while (game->map[i])
	{
		current = ft_strlen(game->map[i]);
		if (game->map[i][current - 1] == '\n')
			current--;
		if (current != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_border(t_game *game, int nb)
{
	int i;
	int end;

	nb--;
	end = ft_strlen(game->map[0]) - 1;
	i = 0;
	while(i <= end)
	{
		if (game->map[0][i] != '1' || game->map[nb][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while(i < nb)
	{
		if (game->map[i][0] != '1' || game->map[i][end] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

