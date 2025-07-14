/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suroh <suroh@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:59:18 by suroh             #+#    #+#             */
/*   Updated: 2025/04/06 19:42:49 by suroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_NUMBER_OF_PHILOS 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				is_eating_now;
	int				meals_eaten;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_of_last_meal;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
	int				*is_dead;
}					t_philo;

typedef struct s_shared_data
{
	size_t			starting_time;
	int				one_dead_flag;
	int				number_of_philosophers;
	int				number_of_times_philo_must_eat;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	t_philo			*philos;
}					t_shared_data;

typedef struct s_monitor_data
{
	t_philo			*philos;
	t_shared_data	*shared;
	int				philo_idx;
}					t_monitor_data;

// initiators.c
void			init_shared_data(t_shared_data *data, t_philo *philos,
					char **argv);
void			init_forks(pthread_mutex_t *forks, int number_of_philosophers);
void			init_philos(t_philo *philos, t_shared_data *data,
					pthread_mutex_t *forks, char **argv);

// monitor.c
void			*monitor(void *arg);

// creating_threads.c
int				create_threads(t_shared_data *data, pthread_mutex_t *forks);

// philo_routine.c
int				yes_i_am_not_dead(t_philo *philo);
void			*philo_routine(void *arg);

// libft_utils.c
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);

// utils.c
void			print_msg(char *str, t_philo *philo, t_shared_data *data,
					int id);
int				upgraded_usleep(size_t ms);
size_t			get_current_time(void);
void			destroy_all(char *str, t_shared_data *data,
					pthread_mutex_t *forks);

#endif
