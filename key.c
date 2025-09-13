/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:50:05 by saibelab          #+#    #+#             */
/*   Updated: 2025/09/13 16:50:05 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode, t_game *game)
{
	int	new_px;
	int	new_py;

	new_px = game->px;
	new_py = game->py;
	if (keycode == 119)
		new_py -= SPEED;
	else if (keycode == 115)
		new_py += SPEED;
	else if (keycode == 97)
		new_px -= SPEED;
	else if (keycode == 100)
		new_px += SPEED;
	if (can_move(game, new_px, new_py))
	{
		game->px = new_px;
		game->py = new_py;
		game->x = game->px / 32;
		game->y = game->py / 32;
		return (1);
	}
	return (0);
}

int	handle_key(int keycode, t_game *game)
{
	static int	moves = 0;

	if (keycode == 65307)
		cleanup(game);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
	{
		if (move_player(keycode, game))
		{
			moves++;
			ft_printf("Move : %d\n", moves);
			collect_if_present(game);
			if (end_exit(game) && all_collected(game))
			{
				ft_printf("Félicitations ! Vous avez terminé le jeu.\n");
				cleanup(game);
			}
		}
	}
	if (killed(game))
		cleanup(game);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 0, close_on_cross, game);
}

int	can_move(t_game *game, int new_px, int new_py)
{
	int	size;

	size = 32;
	if (new_px < 0 || new_py < 0 || new_px + size > game->map_width * 32
		|| new_py + size > game->map_height * 32)
		return (0);
	if (game->map[new_py / 32][new_px / 32] == '1')
		return (0);
	if (game->map[new_py / 32][(new_px + size - 1) / 32] == '1')
		return (0);
	if (game->map[(new_py + size - 1) / 32][new_px / 32] == '1')
		return (0);
	if (game->map[(new_py + size - 1) / 32][(new_px + size - 1) / 32] == '1')
		return (0);
	return (1);
}

int	game_loop(t_game *game)
{
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player, game->px, game->py);
	return (0);
}
