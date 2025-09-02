#include "so_long.h"

int	count_collectible(t_game *game)
{
	int	i;
	int	j;
	int	collectible;

	i = 0;
	collectible = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	game->collectibles = collectible;
	return (collectible);
}

void	collect_if_present(t_game *game)
{
	if (game->map[game->y][game->x] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->collectibles--;
	}
}

int	all_collected(t_game *game)
{
	if (game->collectibles == 0)
		return (1);
	else
		return (0);
}

