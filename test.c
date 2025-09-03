#include "minilibx-linux/mlx.h"
#include <stdlib.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define SPEED 100

typedef struct s_game
{
	void *mlx;
	void *win;
	int x;
	int y;
} t_game;

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 119)
		game->y -= SPEED;
	else if (keycode == 115)
		game->y += SPEED;
	else if (keycode == 97)
		game->x -= SPEED;
	else if (keycode == 100)
		game->x += SPEED;
	else if (keycode == 65307)
		exit(0);
	if (game->x < 0)
		game->x = 0;
	if (game->x > WIN_WIDTH - 1)
		game->x = WIN_WIDTH - 1;
	if (game->y < 0)
		game->y = 0;
	if (game->y > WIN_HEIGHT - 1)
		game->y = WIN_HEIGHT - 1;
	return (0);
}


int	render(void *param)
{
	t_game *game = (t_game *)param;
	int i, j;

	mlx_clear_window(game->mlx, game->win);

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			int px = game->x + j;
			int py = game->y + i;
			if (px >= 0 && px < WIN_WIDTH && py >= 0 && py < WIN_HEIGHT)
				mlx_pixel_put(game->mlx, game->win, px, py, 0xFF0000);
		}
	}

	return (0);
}


int	main(void)
{
	t_game game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "Point Rouge");

	game.x = WIN_WIDTH / 2;
	game.y = WIN_HEIGHT / 2;

	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.win, 2, 1L<<0, handle_key, &game); // key press
	mlx_hook(game.win, 17, 0, (int (*)())exit, 0);   // fermer avec la croix

	mlx_loop(game.mlx);
	return (0);
}
