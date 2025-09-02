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
int	map_init(t_game *game, int fd)
{
	char	*line;
	int		i;
	int len;

	i = 0;
	while ((line = get_next_line(fd)))
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map[i] = gc_malloc(game->gc, len + 1);
		if (!game->map[i])
		{
			free(line);
			return (1);
		}
		ft_strlcpy(game->map[i], line, len + 1);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	return (0);
}

int	map_load(char *args, t_game *game)
{
	int	fd;
	int nb_ligne;

	nb_ligne = count_lines(args);
	if (nb_ligne <= 0)
		return (-1);
	game->map = gc_malloc(game->gc, sizeof(char *) * (nb_ligne + 1));
	if (!game->map)
		return (-1);
	fd = open(args, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (map_init(game, fd))
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (!check_all(game, nb_ligne))
	{
		ft_printf("Debug: check_all failed\n");
		return (-1);
	}
	if (!check_path(game, nb_ligne))
	{
		ft_printf("Debug: check_path failed\n");
		return (-1);
	}
	return (nb_ligne);
}
