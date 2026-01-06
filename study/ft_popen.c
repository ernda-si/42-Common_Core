/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:08:06 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/06 16:26:45 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_popen.h"

static int ft_putstr(char *str)
{
	int i = 0;

	while (str && str[i])
		write(1, &str[i++], 1);
	return (i);
}

int    ft_popen(const char *file, char *const argv[], char type)
{
	int fd[2];

	if (!file || !argv || (type != 'r' && type != 'w'))
		return(-1);
	if (pipe(fd) < 0)
		return (-1);
	pid_t pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
			if (dup2(fd[1], STDOUT_FILENO) < 0)
				exit(-1);
		}
		else if (type == 'w')
		{
			close(fd[1]);
			if (dup2(fd[0], STDIN_FILENO) < 0)
				exit(-1);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);	
		exit(-1);
	}
	if (type == 'r')
	{
		close(fd[1]);
		return (fd[0]);
	}
	else if (type == 'w')
	{
		close(fd[0]);
		return (fd[1]);
	}
	return (-1);
}

int main() {
	int	fd = ft_popen("usr/bin/ls", (char *const[]){"ls", "-l", NULL}, 'w');

	while(ft_putstr(get_next_line(fd)));
}

/* Allowed functions: pipe, fork, dup2, execvp, close, exit

write the following function:

	int    ft_popen(const char file, charconst argv[], char type)

The function must launch the executable file with the arguments argv (using execvp).
If the type is 'r' the function must return a file descriptor connected to the output of the command.
If the type is 'w' the function must return a file descriptor connected to the input of the command.
In case of error or invalid parameter the function must return -1.

example:

int main() {
	int fd = ft_popen("ls", (char const[]){"ls", NULL}, 'r');

	charline;
	while(line = get_next_line(fd))
		ft_putstr(line);
}

Hint: Do not leak file descriptors! */
