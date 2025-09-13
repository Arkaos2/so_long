/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:44:36 by saibelab          #+#    #+#             */
/*   Updated: 2025/09/13 16:44:36 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_monster)
		mlx_destroy_image(game->mlx, game->img_monster);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	gc_destroy(game->gc);
	exit(0);
}

int	close_on_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		cleanup(game);
	return (0);
}

int	close_on_cross(t_game *game)
{
	cleanup(game);
	return (0);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\n: mlx_init a échoué\n");
		gc_destroy(game->gc);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx,
			game->map_width * 32,
			game->map_height * 32,
			"so_long");
	if (!game->win)
	{
		ft_printf("Error\n: impossible de créer la fenêtre\n");
		gc_destroy(game->gc);
		exit(1);
	}
	setup_hooks(game);
	mlx_loop_hook(game->mlx, game_loop, game);
}
