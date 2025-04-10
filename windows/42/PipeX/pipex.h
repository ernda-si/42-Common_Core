/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:59:42 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/10 16:09:57 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**av;
	char	**envp;
	char	**paths;
	int		ac;
	int		files[2];
	int		fds[2];
	int		cmd;
	int		cmd2;
}	t_pipex;

void	pexit(int status, char *error);
void	ft_close_all(t_pipex *p);
void	free_matrix(char **matrix);
void	clean(t_pipex *p);
void	get_paths(t_pipex *p);
void	docmds(t_pipex *p);
void	ft_init_pipex(t_pipex *p);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(char const *str1, char const *str2, int len);
size_t	ft_strlen(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
int		check_infile(t_pipex *p);
void	ft_first_child(t_pipex *p);
int		check_outfile(t_pipex *p);
void	ft_second_child(t_pipex *p);

#endif