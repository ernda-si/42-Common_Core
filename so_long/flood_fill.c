/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:34:34 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/18 13:25:01 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return ;
	game->map[y][x] = '1';
	flood_fill(game, y, x + 1);
	flood_fill(game, y, x - 1);
	flood_fill(game, y + 1, x);
	flood_fill(game, y - 1, x);
	return ;
}
