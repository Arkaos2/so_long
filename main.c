/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:20:55 by saibelab          #+#    #+#             */
/*   Updated: 2025/08/29 15:28:12 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_error("Error\nThis program takes 1 .ber map file\n"), 1);
	if (map_load(argv[1], &game))
	{
		free_map(&game);
		return (ft_error("Error\nInvalid map\n"), 1);
	}
	free_map(&game);
	return (0);
}


