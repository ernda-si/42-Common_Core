/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:28:57 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/17 15:56:31 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall;
	void	*floor;
	void	*coin;
	void	*exit;
	char	**map;
	int		p_x;
	int		p_y;
	int		row;
	int		collum;
	int		win_w;
	int		win_h;
	int		has_coin;
	int		has_player;
	int		has_exit;
	int		move_counter;
	int		gameover;
	int		temp;
	int		exit_x;
	int		exit_y;
}	t_game;

# define BUFFER_SIZE 1

# define IMG_SIZE 50

# define ESC 65307

# define W 119
# define A 97
# define S 115
# define D 100

# define ARROW_UP 65362
# define ARROW_LEFT 65361
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363

# define MOVE_RIGHT 1
# define MOVE_LEFT 1
# define MOVE_UP 1
# define MOVE_DOWN 1

size_t	ft_strlen(const char *str);
void	put_image(t_game *game, void *image, int x, int y);
void	flood_fill(t_game *game, int y, int x);
void	pexit(char *str, int status);
void	move_handler(t_game *game);
void	init_solong(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	free_matrix(char **map);
void	move_up(t_game *game);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	**file_reader(char *map);
char	*get_next_line(int fd);
int		ft_strncmp(char const *str1, char const *str2, int n);
int		generate_map(t_game *game);
int		map_checker(t_game *game);
int		exit_game(t_game *game);
int		end_game(t_game *game);
int		check_path(char **map);
void	free_error(t_game *game);
void	put_exit(t_game *game, int x, int y);
void	free_images(t_game *game, char *str);
void	ft_bzero(void *s, size_t n);

#endif
