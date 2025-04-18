/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:34:26 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/16 19:48:07 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	find_py(char **map)
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
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	game.mlx = NULL;
	game.win = NULL;
	game.player = NULL;
	game.wall = NULL;
	game.floor = NULL;
	game.coin = NULL;
	game.exit = NULL;
	if (ac != 2)
		pexit("arg error", 1);
	name_checker(av[1]);
	game.map = file_reader(av[1]);
	if (!map_checker(&game))
		free_error(&game);
	flood_fill(&game, find_py(game.map), find_px(game.map));
	if (!check_path(game.map))
		free_error(&game);
	free_matrix(game.map);
	game.map = file_reader(av[1]);
	init_solong(&game);
	move_handler(&game);
	mlx_loop(game.mlx);
	return (0);
}
