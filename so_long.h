/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:25:11 by saibelab          #+#    #+#             */
/*   Updated: 2025/09/25 16:29:19 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# define SPEED 4

typedef struct s_gcnode
{
	void			*ptr;
	struct s_gcnode	*next;
}				t_gcnode;

typedef struct s_gc
{
	t_gcnode		*head;
}	t_gc;

typedef struct s_game
{
	char	**map;
	int		x;
	int		y;
	int		px;
	int		py;
	int		collectibles;
	t_gc	*gc;

	void	*mlx;
	void	*win;

	void	*img_monster;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;

	int		map_width;
	int		map_height;
}		t_game;

t_gc	*gc_new(void);

void	load_sprites(t_game *game);
void	draw_map(t_game *game);
void	gc_destroy(t_gc *gc);
void	*gc_malloc(t_gc *gc, size_t size);
void	*ft_error(char *str);
void	count_elements_line(char *line, int *player, int *exit, int *collect);
void	flood_fill(char **map, int x, int y, int nb_lines);
void	find_player(t_game *game, char **map_copy);

int		map_load(char *args, t_game *game);
int		count_lines(char *filename);
int		check_all(t_game *game, int nb);
int		check_elements(t_game *game);
int		check_length(t_game *game);
int		check_border(t_game *game, int nb);
int		check_char(t_game *game);
int		check_path(t_game *game, int nb_lines);

char	*gc_strdup(t_gc *gc, const char *s);

char	**map_parse(t_game *game, int line);

int		handle_key(int keycode, t_game *game);
int		close_on_key(int keycode, t_game *game);
int		close_on_cross(t_game *game);

int		move_player(int keycode, t_game *game);
void	start_game(t_game *game);
void	load_sprites(t_game *game);
void	draw_map(t_game *game);
void	redraw_area(t_game *game, int px, int py);
void	setup_hooks(t_game *game);
void	cleanup(t_game *game);;
int		killed(t_game *game);
int		count_collectible(t_game *game);
void	collect_if_present(t_game *game);
void	collect_in_range(t_game *game, int center_x, int center_y, int margin);
int		all_collected(t_game *game);
int		move_count(int keycode, t_game *game);
void	draw_pixel(t_game *game, int x, int y);
void	redraw_area(t_game *game, int px, int py);
void	handle_movement(int keycode, t_game *game, int *moves);
int		can_move(t_game *game, int new_px, int new_py);
int		end_exit(t_game *game);
void	collect_at(t_game *game, int x, int y);

#endif
