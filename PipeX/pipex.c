/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:43:16 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/10 16:15:58 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_paths(t_pipex *p)
{
	char	*path_parse;
	char	**paths;
	char	*tmp;
	int		i;

	i = 0;
	while (p->envp[i])
	{
		if (ft_strnstr(p->envp[i], "PATH", 5))
			path_parse = p->envp[i];
		i++;
	}
	path_parse = ft_substr (path_parse, 5, ft_strlen(path_parse));
	paths = ft_split (path_parse, ':');
	i = -1;
	while (paths[++i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin (tmp, "/");
		if (tmp)
			free (tmp);
	}
	p->paths = paths;
	free(path_parse);
}

void	docmds(t_pipex *p)
{
	p->cmd = fork ();
	if (p->cmd < 0)
		pexit (1, "fork");
	else if (p->cmd == 0)
		ft_first_child(p);
	p->cmd2 = fork ();
	if (p->cmd2 < 0)
		pexit (1, "fork");
	else if (p->cmd2 == 0)
		ft_second_child(p);
}

void	ft_init_pipex(t_pipex *p)
{
	int	status;

	if (pipe (p->fds) < 0)
	{
		clean(p);
		pexit (1, "pipe");
	}
	docmds(p);
	ft_close_all(p);
	waitpid(p->cmd, &status, 0);
	waitpid(p->cmd2, &status, 0);
	if (WIFEXITED (status))
	{
		clean(p);
		exit (WEXITSTATUS (status));
	}
	else
	{
		clean(p);
		exit (1);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*p;

	if (ac != 5)
	{
		write(1, "/pipex [in_file] '[cmd1]' '[cmd2]' [out_file]\n", 47);
		exit(1);
	}
	else if (av[1][0] == '\0' || av[4][0] == '\0')
		exit(1);
	p = (t_pipex *) malloc(sizeof(t_pipex));
	p->av = av;
	p->envp = envp;
	p->ac = ac;
	get_paths(p);
	p->files[0] = open(av[1], O_RDONLY);
	if (access(p->av[4], F_OK) == -1)
		unlink(av[4]);
	p->files[1] = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	ft_init_pipex(p);
}
