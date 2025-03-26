/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:43:16 by ernda-si          #+#    #+#             */
/*   Updated: 2025/03/26 15:52:52 by ernda-si         ###   ########.fr       */
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
// pegar primeiro resultado e executar segundo comando
// por o resultado final na outfile com pipe[0];
// criar handler de erros

void	ft_close_all(int fds[2])
{
	close(fds[0]);
	close(fds[1]);
}

int	ft_check_infile(char **av)
{
	if (access(av[1], F_OK) == -1)
	{
		printf ("PipeX: file %s does not exist!\n", av[1]);
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
	int	fd;
	
	fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error");
		close(fd);
		exit(1);
	}
	// if (access(av[4], F_OK) != -1)
	// {
		// if (access (av[4], W_OK) == -1)
		// {
		// 	printf ("PipeX: write permission denied: %s\n", av[4]);
		// 	exit (1);
		// }
	// }
	return (fd);
}

int	ft_exec(t_pipex p)
{
	if (p.cmds > 0)
	{
		dup2 (p.files[0], 0);
		dup2 (p.fds[1], 1);
		ft_close_all(p.fds);
		ft_close_all(p.files);
		execve ("/bin/bash", (char *[]){"bash", "-c", p.av[2], NULL}, p.envp);
		write(1, "execution failed!\n", 19);
		exit (1);
	}
	if (p.cmds == 0)
	{
		dup2 (p.fds[0], 0);
		dup2 (p.files[1], 1);
		ft_close_all(p.fds);
		ft_close_all(p.files);
		execve ("/bin/bash", (char *[]){"bash", "-c", p.av[3], NULL}, p.envp);
		write(1, "execution failed!\n", 19);
		exit (1);
	}
	return (1);
}

int	ft_init_pipex(t_pipex p)
{
	if (pipe (p.fds) == -1)
	{
		perror ("pipe");
		exit (1);
	}
	p.cmds = fork ();
	if (p.cmds < 0)
	{
		ft_close_all(p.files);
		ft_close_all(p.fds);
		printf ("fork error!\n");
		exit (1);
	}
	else
	{
		ft_exec(p);
	}
	ft_close_all(p.fds);
	ft_close_all(p.files);
	waitpid(p.cmds, NULL, 0);
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
	return (1);
}
