/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:43:16 by ernda-si          #+#    #+#             */
/*   Updated: 2025/03/24 15:10:00 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeX.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// verificar se a infile is valid -> existencia e permissoes;
// executar primeiro comando na infile
// pegar primeiro resultado e executar segundo comando
// por o resultado final na outfile
// criar handler de erros

int	main(int ac, char **av, char **envp)
{
	int	in_fd;
	int	out_fd;
	pid_t cmd1;
	// pid_t cmd2;

	cmd1 = fork();
	(void)ac;

	// verificar se a infile is valid -> existencia e permissoes;
	if (access(av[1], F_OK) != -1 && access(av[1], R_OK) != -1)
	{
		in_fd = open(av[1], O_RDONLY);
		out_fd = open(av[3], O_WRONLY | O_CREAT, 0664);
	}
	else
		return(printf("PipeX: permission denied: %s\n", av[1]));

	dup2(out_fd, 1);
	if (cmd1 == 0)
		execve("/bin/bash", (char *[]){"bash", "-c", av[2], NULL}, envp);

	close(in_fd);
	close(out_fd);
	
	return (0);
}
