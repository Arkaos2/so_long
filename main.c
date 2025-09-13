/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:20:55 by saibelab          #+#    #+#             */
/*   Updated: 2025/09/13 16:49:36 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		nb_lines;

	if (argc != 2)
		return (ft_error("Error\n: ./so_long <map.ber>"), 1);
	game.gc = gc_new();
	if (!game.gc)
		return (1);
	nb_lines = map_load(argv[1], &game);
	if (nb_lines == -1)
	{
		ft_printf("Error\n: map invalide ou fichier introuvable.\n");
		gc_destroy(game.gc);
		return (1);
	}
	game.map_width = ft_strlen(game.map[0]);
	game.map_height = nb_lines;
	game.collectibles = count_collectible(&game);
	start_game(&game);
	load_sprites(&game);
	draw_map(&game);
	mlx_loop(game.mlx);
	gc_destroy(game.gc);
	return (0);
}
