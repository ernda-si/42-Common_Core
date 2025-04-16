#include "so_long.h"

static void	update_player(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->player);
	if (key == 'w' || key == 'a' || key == 's' || key == 'd')
		game->player = mlx_xpm_file_to_image
			(game->mlx, "assets/player.xpm", &game->row, &game->collum);
}

void	move_up(t_game *game)
{
	update_player('w', game);
	if (game->map[game->p_y][game->p_x] == 'E' && game->has_coin == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->p_y + 1][game->p_x] = '0';
		game->move_counter++;
		game->gameover = 1;
		game->has_player = 0;
		generate_map(game);
	}
	else if (game->map[game->p_y][game->p_x] == '1' || game->map[game->p_y][game->p_x] == 'E')
		game->p_y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_y][game->p_x] == 'C')
			game->has_coin -= 1;
		game->map[game->p_y][game->p_x] = 'P';
		game->map[game->p_y + 1][game->p_x] = '0';
		game->move_counter++;
		generate_map(game);
	}
}

void	move_left(t_game *game)
{
	update_player('a', game);
	if (game->map[game->p_y][game->p_x] == 'E' && game->has_coin == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->p_y][game->p_x + 1] = '0';
		game->move_counter++;
		game->gameover = 1;
		game->has_player = 0;
		generate_map(game);
	}
	else if (game->map[game->p_y][game->p_x] == '1' || game->map[game->p_y][game->p_x] == 'E')
		game->p_x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_y][game->p_x] == 'C')
			game->has_coin -= 1;
		game->map[game->p_y][game->p_x] = 'P';
		game->map[game->p_y][game->p_x + 1] = '0';
		game->move_counter++;
		generate_map(game);
	}
}

void	move_down(t_game *game)
{
	update_player('s', game);
	if (game->map[game->p_y][game->p_x] == 'E' && game->has_coin == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->p_y - 1][game->p_x] = '0';
		game->move_counter++;
		game->gameover = 1;
		game->has_player = 0;
		generate_map(game);
	}
	else if (game->map[game->p_y][game->p_x] == '1' || game->map[game->p_y][game->p_x] == 'E')
		game->p_y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_y][game->p_x] == 'C')
			game->has_coin -= 1;
		game->map[game->p_y][game->p_x] = 'P';
		game->map[game->p_y - 1][game->p_x] = '0';
		game->move_counter++;
		generate_map(game);
	}
}

void	move_right(t_game *game)
{
	update_player('d', game);
	if (game->map[game->p_y][game->p_x] == 'E' && game->has_coin == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->p_y][game->p_x - 1] = '0';
		game->move_counter++;
		game->gameover = 1;
		game->has_player = 0;
		generate_map(game);
	}
	else if (game->map[game->p_y][game->p_x] == '1' || game->map[game->p_y][game->p_x] == 'E')
		game->p_x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->p_y][game->p_x] == 'C')
			game->has_coin -= 1;
		game->map[game->p_y][game->p_x] = 'P';
		game->map[game->p_y][game->p_x - 1] = '0';
		game->move_counter++;
		generate_map(game);
	}
}
