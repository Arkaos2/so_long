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

int main(int argc, char **argv)
{
	t_game game;
	if (argc != 2)
	{
		ft_error("Error\nThis programe take 1 argument .ber\n");
		return (0);
	}
	map_check(argv[1], &game);
}
