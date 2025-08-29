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

int count_lines(char *filename)
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

int check_all(t_game *game, int nb)
{
	if(!check_lenght(game))
		return (1);
	if(!check_border(game, nb))
		return (1);
	if(!check_elements(game))
		return (1);
	if(!check_char(game))
		return (1);

}

int	map_load(char *args, t_game *game)
{
	int	fd;
	int	i;
	char *line;
	int nb_ligne;

	nb_ligne = count_lines(args);
	game->map = malloc(sizeof(char *) * (nb_ligne + 1));
	if (!game->map)
		return (1);
	i = 0;
	fd = open(args, O_RDONLY);
	while((line = get_next_line(fd)))
	{

		if(map_check(line))
			game->map[i++] = line;
		else
			return (1);
	}
	game->map[i] = NULL;
	close(fd);
	return(0);
}
