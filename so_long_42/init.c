#include "so_long.h"

static void	img_init(t_game *game)
{
	game->player = mlx_xpm_file_to_image
		(game->mlx, "assets/player.xpm", &game->row, &game->collum);
	if (!game->player)
		pexit("player xpm modified!\n", 1);
	game->floor = mlx_xpm_file_to_image
		(game->mlx, "assets/floor.xpm", &game->row, &game->collum);
	if (!game->floor)
		pexit("floor xpm modified!\n", 1);
	game->wall = mlx_xpm_file_to_image
		(game->mlx, "assets/wall.xpm", &game->row, &game->collum);
	if (!game->wall)
		pexit("wall xpm modified!\n", 1);
	game->coin = mlx_xpm_file_to_image
		(game->mlx, "assets/coin.xpm", &game->row, &game->collum);
	if (!game->coin)
		pexit("coin xpm modified!\n", 1);
	game->exit = mlx_xpm_file_to_image
		(game->mlx, "assets/exit.xpm", &game->row, &game->collum);
	if (!game->exit)
		pexit("exit xpm modified!\n", 1);
}

static void	get_window_size(t_game *game)
{
	int	i;

	game->size_x = ft_strlen(game->map[0]) * IMG_SIZE;
	i = 0;
	while (game->map[i])
		i++;
	game->size_y = i * IMG_SIZE;
}

void	init_solong(t_game *game)
{
	game->mlx = mlx_init();
	get_window_size(game);
	game->win = mlx_new_window(game->mlx, game->size_x, game->size_y, "so_long");
	game->move_counter = 0;
	game->gameover = 0;
	img_init(game);
	generate_map(game);
}
