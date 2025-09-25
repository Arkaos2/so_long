/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:56:01 by saibelab          #+#    #+#             */
/*   Updated: 2025/09/13 16:56:01 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_game *g)
{
	int	w;
	int	h;

	g->img_wall = mlx_xpm_file_to_image(g->mlx, "t/1.xpm", &w, &h);
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "t/0.xpm", &w, &h);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "t/p.xpm", &w, &h);
	g->img_collect = mlx_xpm_file_to_image(g->mlx, "t/c.xpm", &w, &h);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "t/e.xpm", &w, &h);
	g->img_monster = mlx_xpm_file_to_image(g->mlx, "t/m.xpm", &w, &h);
	(void)w;
	(void)h;
}

void	draw_pixel(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x * 32, y * 32);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, x * 32, y * 32);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collect, x * 32, y * 32);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, x * 32, y * 32);
	else if (game->map[y][x] == 'M')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_monster, x * 32, y * 32);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_pixel(game, x, y);
			x++;
		}
		y++;
	}
}

void	redraw_area(t_game *game, int px, int py)
{
	int	x_start;
	int	y_start;
	int	x;
	int	y;

	x_start = px / 32;
	y_start = py / 32;
	y = y_start;
	while (y <= (py + 31) / 32 && y < game->map_height)
	{
		x = x_start;
		while (x <= (px + 31) / 32 && x < game->map_width)
		{
			if (x >= 0 && y >= 0)
				draw_pixel(game, x, y);
			x++;
		}
		y++;
	}
}
