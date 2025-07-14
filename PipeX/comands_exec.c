/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:02:46 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/10 16:10:18 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_infile(t_pipex *p)
{
	if (!p->av[2] || p->av[2][0] == '\0')
	{
		clean(p);
		pexit(1, "command is empty");
	}
	if (access(p->av[1], F_OK | R_OK) == -1)
	{
		ft_close_all(p);
		clean (p);
		perror ("Infile");
		exit (1);
	}
	return (-1);
}

void	ft_first_child(t_pipex *p)
{
	char	*cmd;
	char	**mycmd;
	int		i;

	i = check_infile(p);
	dup2 (p->files[0], 0);
	dup2 (p->fds[1], 1);
	ft_close_all (p);
	mycmd = ft_split(p->av[2], ' ');
	while (p->paths[++i])
	{
		if (access (p->av[2], F_OK) == -1)
			cmd = ft_strjoin(p->paths[i], mycmd[0]);
		else
			cmd = ft_strdup(p->av[2]);
		if (access (cmd, X_OK) == 0)
			execve (cmd, mycmd, p->envp);
		if (cmd)
			free(cmd);
	}
	if (mycmd || mycmd[0])
		free_matrix(mycmd);
	perror ("execution failed!");
	clean(p);
	exit (1);
}

int	check_outfile(t_pipex *p)
{
	if (!p->av[4] || p->av[4][0] == '\0')
	{
		clean(p);
		pexit(1, "command is empty");
	}
	if (access(p->av[4], F_OK | W_OK) == -1)
	{
		perror ("Outfile");
		free_matrix(p->paths);
		free(p);
		exit (1);
	}
	return (-1);
}

void	ft_second_child(t_pipex *p)
{
	char	*cmd;
	char	**mycmd;
	int		i;

	i = check_outfile(p);
	dup2 (p->fds[0], 0);
	dup2 (p->files[1], 1);
	ft_close_all (p);
	mycmd = ft_split(p->av[3], ' ');
	while (p->paths[++i])
	{
		if (access (p->av[3], F_OK) == -1)
			cmd = ft_strjoin(p->paths[i], mycmd[0]);
		else
			cmd = ft_strdup(p->av[i]);
		if (access (cmd, X_OK) == 0)
			execve (cmd, mycmd, p->envp);
		if (cmd)
			free(cmd);
	}
	if (mycmd || mycmd[0])
		free_matrix(mycmd);
	clean(p);
	pexit(127, "execution");
}
