#include "so_long.h"

static int	check_shape(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

static int check_walls(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_elements(t_game *game)
{
	int	i;
	int	j;

	game->has_coin = 0;
	game->has_player = 0;
	game->has_exit = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				game->has_player++;
			else if (game->map[i][j] == 'C')
				game->has_coin++;
			else if (game->map[i][j] == 'E')
				game->has_exit++;
			j++;
		}
		i++;
	}
	if (game->has_player != 1 || game->has_exit != 1 || game->has_coin <= 0 )
		return (0);
	return (1);
}

static int	map_validation(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_checker(t_game *game)
{
	if (check_shape(game->map) && check_walls(game->map) && check_elements(game) && map_validation(game->map))
		return (1);
	return (0);
}

