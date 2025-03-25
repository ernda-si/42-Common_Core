/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:43:16 by ernda-si          #+#    #+#             */
/*   Updated: 2025/03/25 14:00:02 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// verificar se a infile is valid -> existencia / leitura;
// verificar se a outfile is valid -> existencia / leitura / truncation;
// executar primeiro comando na infile;
// utilizar pipe para guardar o resultado do primeiro comando pipe[1];
// pegar primeiro resultado e executar segundo comando
// por o resultado final na outfile com pipe[0];
// criar handler de erros

int	ft_check_infile(char **av)
{
	if (access(av[1], F_OK) == -1)
	{
		printf ("PipeX: file %s does not exist!", av[1]);
		exit (1);
	}
	else if (access (av[1], R_OK) == -1)
	{
		printf ("PipeX: read permission denied: %s\n", av[1]);
		exit (1);
	}
	return (open(av[1], O_RDONLY));
}

int	ft_check_outfile(char **av)
{
	if (access(av[4], F_OK) == -1)
	{
		printf ("PipeX: file %s does not exist!", av[4]);
		exit (1);
	}
	else if (access (av[4], W_OK) == -1)
	{
		printf ("PipeX: write permission denied: %s\n", av[4]);
	}
	return (open(av[4], O_WRONLY | O_CREAT | O_TRUNC));
}

int	ft_exec(t_pipex p)
{
	if (p.cmds > 0)
	{
		dup2 (p.files[0], 0);
		dup2 (p.fds[1], 1);
		close (p.fds[0]);
		close (p.fds[1]);
		close (p.files[0]);
		close (p.files[1]);
		execve ("/bin/bash", (char *[]){"bash", "-c", p.av[2], NULL}, p.envp);
		exit (EXIT_FAILURE);
	}
	if (p.cmds == 0)
	{
		dup2 (p.fds[0], 0);
		dup2 (p.files[1], 1);
		close (p.fds[0]);
		close (p.fds[1]);
		close (p.files[0]);
		close (p.files[1]);
		execve ("/bin/bash", (char *[]){"bash", "-c", p.av[3], NULL}, p.envp);
		exit (EXIT_FAILURE);
	}
	return (1);
}

int	ft_init_pipex(t_pipex p)
{
	if (pipe (p.fds) == -1)
	{
		perror ("pipe");
		exit (EXIT_FAILURE);
	}
	p.cmds = fork ();
	if (p.cmds == -1)
	{
		printf ("fork error!\n");
		exit (1);
	}
	else
		ft_exec (p);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	p;

	p.av = av;
	p.envp = envp;
	(void) ac;
	if (ac != 5)
	{
		printf("/pipex [in_file] '[cmd1]' '[cmd2]' [out_file]\n");
		exit(1);
	}
	p.files[0] = ft_check_infile(p.av);
	p.files[1] = ft_check_outfile(p.av);
	ft_init_pipex(p);
	return (0);
}
