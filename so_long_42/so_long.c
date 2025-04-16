#include "so_long.h"

void	pexit(char *str, int status)
{
	int	w;

	w = 0;
	w += write(2, str, ft_strlen(str));
	exit(status);
}

static void	name_checker(char *file_name)
{
	file_name = file_name + (ft_strlen(file_name) - 4);
	if (ft_strncmp(file_name, ".ber", 4))
		pexit("missing .ber", 1);
}

int	find_px(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return 0;
	if (map[y][x] != 'E')
		return 1;
	map[y][x] = 'F';
	flood_fill(map[y][x + 1]);
	flood_fill(map[y][x - 1]);
	flood_fill(map[y + 1][x]);
	flood_fill(map[y - 1][x]);
	return ;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		pexit("arg error", 1);
	name_checker(av[1]);
	game.map = file_reader(av[1]);
	if (!map_checker(&game))
	{
		if (game.map)
			free_matrix(game.map);
		pexit("map invalid", 1);
	}
	floodfill(game.map, find_px(game.map), find_py(game.map));
	init_solong(&game);
	move_handler(&game);
	mlx_loop(game.mlx);
	return (0);
}
