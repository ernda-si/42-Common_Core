/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:59:18 by suroh             #+#    #+#             */
/*   Updated: 2025/08/27 03:40:17 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				*dead;
	int				eating;
	int				eaten_meals;
	size_t			t_eat;
	size_t			t_die;
	size_t			t_sleep;
	size_t			t_last_meal;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}					t_philo;

typedef struct s_program
{
	size_t			t_start;
	int				one_dead_flag;
	int				max_philos;
	int				n_still_eat;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	t_philo			*philos;
}					t_program;

typedef struct s_monitor_program
{
	t_philo			*philos;
	t_program	*shared;
	int				philo_idx;
}					t_monitor_program;

size_t	ft_strlen(const char *str);
size_t	get_current_time(void);
void	init_philos(char **av, t_philo *philos, t_program *program, pthread_mutex_t *forks);
void	kill_all(char *str, t_program *program, pthread_mutex_t *forks);
void	print_msg(char *str, t_philo *philo, t_program *program, int id);
void	init_program(char **av, t_program *program, t_philo *philos);
void	to_sleep(t_philo *philo, t_monitor_program *monitorer);
void	init_forks(pthread_mutex_t *forks, int max_philos);
void	eat(t_philo *philo, t_monitor_program *monitorer);
void	think(t_philo *philo, t_monitor_program *program);
void	*philo_routine(void *arg);
void	*monitor(void *arg);
int		create_threads(t_program *program, pthread_mutex_t *forks);
int		dead_lock(t_philo *philo);
int		upgraded_usleep(size_t ms);
int		ft_atoi(const char *nptr);
int		check_valid(char **av);
int		ft_isdigit(int c);

#endif
