#include "so_long.h"

int	move_player(int keycode, t_game *game)
{
	int	old_x;
	int	old_y;

	old_x = game->x;
	old_y = game->y;
	if (keycode == 119 && game->y > 0 && game->map[game->y - 1][game->x] != '1') // W
		game->y--;
	else if (keycode == 115 && game->y < game->map_height - 1 && game->map[game->y + 1][game->x] != '1') // S
		game->y++;
	else if (keycode == 97 && game->x > 0 && game->map[game->y][game->x - 1] != '1') // A
		game->x--;
	else if (keycode == 100 && game->x < game->map_width - 1 && game->map[game->y][game->x + 1] != '1') // D
		game->x++;
	collect_if_present(game);
	if (game->map[old_y][old_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, old_x * 32, old_y * 32);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, old_x * 32, old_y * 32);
	mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->x * 32, game->y * 32);
	if (game->map[game->y][game->x] == 'E' && all_collected(game))
	{
		ft_printf("Félicitations ! Vous avez terminé le jeu.\n");
		cleanup(game);
	}
	return (old_x != game->x || old_y != game->y);
}

int	handle_key(int keycode, t_game *game)
{
	static int moves = 0;

	if (keycode == 65307)
		cleanup(game);

	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
	{
		if (move_player(keycode, game))
		{
			moves++;
			ft_printf("Move : %d\n", moves);
		}
	}
	if(killed(game))
		cleanup(game);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L<<0, handle_key, game);
	mlx_hook(game->win, 17, 0, close_on_cross, game);
}
