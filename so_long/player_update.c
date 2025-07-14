/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:34:47 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/21 13:19:18 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->p_y][game->p_x] == 'E' && game->has_coin == 0)
		end_game(game);
	else if (game->map[game->p_y][game->p_x] == '1')
		game->p_y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_y][game->p_x] == 'C')
		{
			game->has_coin -= 1;
			if (game->has_coin == 0)
			{
				game->map[game->p_y][game->p_x] = 'P';
				game->map[game->p_y + 1][game->p_x] = '0';
				game->map[game->exit_y][game->exit_x] = 'E';
				game->move_counter++;
				generate_map(game);
				return ;
			}
		}
		game->map[game->p_y][game->p_x] = 'P';
		game->map[game->p_y + 1][game->p_x] = '0';
		game->move_counter++;
		generate_map(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->p_y][game->p_x] == 'E' && game->has_coin == 0)
		end_game(game);
	else if (game->map[game->p_y][game->p_x] == '1')
		game->p_x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_y][game->p_x] == 'C')
		{
			game->has_coin -= 1;
			if (game->has_coin == 0)
			{
				game->map[game->p_y][game->p_x] = 'P';
				game->map[game->p_y][game->p_x + 1] = '0';
				game->map[game->exit_y][game->exit_x] = 'E';
				game->move_counter++;
				generate_map(game);
				return ;
			}
		}
		game->map[game->p_y][game->p_x] = 'P';
		game->map[game->p_y][game->p_x + 1] = '0';
		game->move_counter++;
		generate_map(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->p_y][game->p_x] == 'E' && game->has_coin == 0)
		end_game(game);
	else if (game->map[game->p_y][game->p_x] == '1')
		game->p_y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_y][game->p_x] == 'C')
		{
			game->has_coin -= 1;
			if (game->has_coin == 0)
			{
				game->map[game->p_y][game->p_x] = 'P';
				game->map[game->p_y - 1][game->p_x] = '0';
				game->map[game->exit_y][game->exit_x] = 'E';
				game->move_counter++;
				generate_map(game);
				return ;
			}
		}
		game->map[game->p_y][game->p_x] = 'P';
		game->map[game->p_y - 1][game->p_x] = '0';
		game->move_counter++;
		generate_map(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->p_y][game->p_x] == 'E' && game->has_coin == 0)
		end_game(game);
	else if (game->map[game->p_y][game->p_x] == '1')
		game->p_x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_y][game->p_x] == 'C')
		{
			game->has_coin -= 1;
			if (game->has_coin == 0)
			{
				game->map[game->p_y][game->p_x] = 'P';
				game->map[game->p_y][game->p_x -1] = '0';
				game->map[game->exit_y][game->exit_x] = 'E';
				game->move_counter++;
				generate_map(game);
				return ;
			}
		}
		game->map[game->p_y][game->p_x] = 'P';
		game->map[game->p_y][game->p_x - 1] = '0';
		game->move_counter++;
		generate_map(game);
	}
}
