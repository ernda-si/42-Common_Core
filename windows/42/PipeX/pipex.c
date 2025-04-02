/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:43:16 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/02 18:55:04 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// verificar se a infile is valid -> existencia / leitura;
// verificar se a outfile is valid -> existencia / leitura / truncation;
// executar primeiro comando na infile;
// utilizar pipe para guardar o resultado do primeiro comando pipe[1];
// pegar primeiro resultado e executar segundo comando;
// por o resultado final na outfile com pipe[0];
// criar handler de erros;

void	ft_close_all(t_pipex p)
{
	close(p.files[0]);
	close(p.files[1]);
	close(p.fds[0]);
	close(p.fds[1]);
}

int	ft_check_infile(char **av)
{
/* 	if (access(av[1], F_OK) == -1)
		perror ("PipeX: file %s does not exist!\n", av[1]);
	else if (access (av[1], R_OK) == -1)
		perror ("PipeX: read permission denied: %s\n", av[1]); */
	return (open(av[1], O_RDONLY));
}

int	ft_check_outfile(char **av)
{
	return (open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0666));
}

void	ft_first_child(t_pipex p)
{
	if (access(p.av[1], F_OK | R_OK) == -1)
	{
		perror ("Error");
		exit (1);
	}
	dup2 (p.files[0], 0);
	dup2 (p.fds[1], 1);
	ft_close_all (p);
	execve ("/bin/bash", (char *[]){"bash", "-c", p.av[2], NULL}, p.envp);
	perror ("execution failed!\n");
	exit (1);
}
	
void	ft_second_child(t_pipex p)
{
	if (access(p.av[4], F_OK | W_OK) == -1)
	{
		perror ("Error");
		exit (1);
	}
	dup2 (p.fds[0], 0);
	dup2 (p.files[1], 1);
	ft_close_all (p);
	execve ("/bin/bash", (char *[]){"bash", "-c", p.av[3], NULL}, p.envp);
	perror ("execution failed!\n");
	exit (1);
}

void	ft_init_pipex(t_pipex p)
{
	if (pipe (p.fds) == -1)
	{
		perror ("pipe");
		exit (1);
	}
	p.cmd = fork ();
	if (p.cmd < 0)
	{
		printf ("fork error!\n");
		exit (1);
	}
	else if (p.cmd == 0)
		ft_first_child(p);
	p.cmd2 = fork ();
	if (p.cmd2 < 0)
	{
		printf ("fork error!\n");
		exit (1);
	}
	else if (p.cmd2 == 0)
		ft_second_child(p);
	ft_close_all(p);
	waitpid(p.cmd, NULL, 0);
	waitpid(p.cmd2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	p;

	p.av = av;
	p.envp = envp;
	(void) ac;
	if (ac != 5)
	{
		write(1, "/pipex [in_file] '[cmd1]' '[cmd2]' [out_file]\n", 47);
		exit(1);
	}
	p.files[0] = ft_check_infile(p.av);
	p.files[1] = ft_check_outfile(p.av);
	ft_init_pipex(p);
}
