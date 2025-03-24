/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:54:28 by ernda-si          #+#    #+#             */
/*   Updated: 2025/03/24 15:28:53 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeX.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// int pipe(int fds[2]);
//Parameters :fd[0] will be the fd(file descriptor) for the read end of pipe.
// fd[1] will be the fd for the write end of pipe.
// Returns : 0 on Success.
// -1 on error.

int	main (void)
{
	pid_t pid;
	int pi[2];
	char	buff[256];
	
	if (pipe(pi) < 0)
		exit(1);

	write(pi[1], "abc",256);
	fork();
	if (pid < 0)
	{
		perror ("fork failure");
		exit (1);
	}
	else if (pid == 0)
		printf ("child's pid: %d\n", getpid());
	else
		printf ("parent's pid: %d\n", getpid());
	read(pi[0], buff, 256);
	printf("buffer: %s\n", buff);
	return (0);
}