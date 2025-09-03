#include "so_long.h"

void	load_sprites(t_game *game)
{
	int w;
	int h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "texture/1.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "texture/0.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "texture/p.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "texture/c.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "texture/e.xpm", &w, &h);
	game->img_monster = mlx_xpm_file_to_image(game->mlx, "texture/p2.xpm", &w, &h);
	(void)w;
	(void)h;
}

void	draw_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 32, y * 32);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * 32, y * 32);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collect, x * 32, y * 32);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 32, y * 32);
			else if (game->map[y][x] == 'M')
				mlx_put_image_to_window(game->mlx, game->win, game->img_monster, x * 32, y * 32);
			x++;
		}
		y++;
	}
}


