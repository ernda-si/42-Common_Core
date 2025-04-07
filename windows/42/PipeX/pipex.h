/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:59:42 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/07 15:51:17 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipex
{
	char	**av;
	char	**envp;
	int		files[2];
	int		fds[2];
	int		cmds;
	int		cmd;
	int		cmd2;
}	t_pipex;

void	ft_init_pipex(t_pipex p);
void	ft_close_all(t_pipex p);
void	ft_exec(t_pipex p);
int		ft_check_outfile(char **av);
int		ft_check_infile(char **av);

#endif