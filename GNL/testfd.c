/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:55:50 by ernda-si          #+#    #+#             */
/*   Updated: 2024/06/17 16:08:43 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	buff[BUFFER_SIZE + 1];
	int	fd = open("test.txt", O_RDONLY);
	read(fd, buff, BUFFER_SIZE + 0);
	printf("%s\n", buff);
	close(fd);
}
