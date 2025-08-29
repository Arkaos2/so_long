/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:04:17 by saibelab          #+#    #+#             */
/*   Updated: 2025/08/29 18:53:42 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *filename)
{
	int fd;
	int count = 0;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

// int	check_all(t_game *game, int nb)
// {
// 	if(!check_length(game))
// 		return (0);
// 	if(!check_border(game, nb))
// 		return (0);
// 	if(!check_elements(game))
// 		return (0);
// 	if(!check_char(game))
// 		return (0);
// 	return (1);
// }

int	check_all(t_game *game, int nb)
{
	if (!check_length(game))
	{
		ft_printf("DEBUG: check_length failed\n");
		return (0);
	}
	if (!check_border(game, nb))
	{
		ft_printf("DEBUG: check_border failed\n");
		return (0);
	}
	if (!check_elements(game))
	{
		ft_printf("DEBUG: check_elements failed\n");
		return (0);
	}
	if (!check_char(game))
	{
		ft_printf("DEBUG: check_char failed\n");
		return (0);
	}
	return (1);
}

int	map_load(char *args, t_game *game)
{
	int		fd;
	int		i;
	char	*line;
	int		nb_ligne;

	nb_ligne = count_lines(args);
	game->map = malloc(sizeof(char *) * (nb_ligne + 1));
	if (!game->map)
		return (1);
	fd = open(args, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map[i++] = line;
	}
	game->map[i] = NULL;
	close(fd);
	if (!check_all(game, nb_ligne))
	{
		free_map(game);
		return (1);
	}
	return (0);
}

