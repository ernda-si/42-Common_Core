/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:33:33 by kali              #+#    #+#             */
/*   Updated: 2025/02/07 11:34:06 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#   include <stdio.h>
#   include <unistd.h>
#   include <stdlib.h>
#   include <fcntl.h>
#	include "mlx_linux/mlx.h"
// #   include <mlx.h>

#	define IMG_SIZE 50;

typedef struct s_imgs {
	void	*img;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*background;
	void	*player;
	void	*exit;
	// void	*enemy; (bonus)
}	t_imgs;

typedef struct s_player {
	int posX;
	int posY;
} t_player;

typedef struct	s_map {
	void	*mlx;
	void	*win;
	t_imgs	img;
	t_player player;
}				t_map;

size_t	ft_strlen(const char *str);
void	my_mlx_pixel_put(t_imgs *data, int x, int y, int color);
char	*ft_strjoin(char *line, char *buff, size_t	line_len, size_t buff_len);
char	*get_next_line(int fd);
int		map_checker(void);
int		check_walls(char *line);
int		cut_buff(char *buffer);
int		close_win(int keycode, t_map *vars);
int		get_x(void);
int		get_y(void);

#endif