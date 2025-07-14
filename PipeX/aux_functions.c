/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:15:12 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/10 16:15:50 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pexit(int status, char *error)
{
	perror(error);
	exit(status);
}

void	ft_close_all(t_pipex *p)
{
	if (p->files[0] > -1)
		close(p->files[0]);
	if (p->files[1] > -1)
		close(p->files[1]);
	close(p->fds[0]);
	close(p->fds[1]);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix && matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	clean(t_pipex *p)
{
	if (p->paths)
	{
		free_matrix(p->paths);
		p->paths = NULL;
	}
	if (!p->cmd)
		p->cmd = 0;
	free(p);
}
