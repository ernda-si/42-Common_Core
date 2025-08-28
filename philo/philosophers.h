/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:59:18 by ernda-si          #+#    #+#             */
/*   Updated: 2025/08/28 15:35:32 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_philo
{
	int				id;
	int				*dead;
	int				eating;
	int				eaten_meals;
	size_t			t_eat;
	size_t			t_die;
	size_t			t_sleep;
	size_t			t_last_meal;
	pthread_t		thread;
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
	t_philo		*philos;
	t_program	*shared;
	int			philo_idx;
}					t_monitor_program;

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define RESET		"\033[0m"

# define BG_BLACK	"\033[40m"
# define BG_RED		"\033[41m"
# define BG_GREEN	"\033[42m"
# define BG_YELLOW	"\033[43m"
# define BG_BLUE	"\033[44m"
# define BG_MAGENTA	"\033[45m"
# define BG_CYAN	"\033[46m"
# define BG_WHITE	"\033[47m"

# define BOLD		"\033[1m"
# define UNDER		"\033[4m"

size_t	ft_strlen(const char *str);
size_t	get_current_time(void);
void	init_philos(char **av, t_philo *philos, t_program *program,
			pthread_mutex_t *forks);
void	kill_all(char *str, t_program *program, pthread_mutex_t *forks);
void	print_task(char *str, t_philo *philo, t_program *program, int id);
void	init_program(char **av, t_program *program, t_philo *philos);
void	to_sleep(t_philo *philo, t_monitor_program *monitorer);
void	init_forks(pthread_mutex_t *forks, int max_philos);
void	eat(t_philo *philo, t_monitor_program *monitorer);
void	think(t_philo *philo, t_monitor_program *program);
void	*routine(void *arg);
void	*monitor(void *arg);
int		create_threads(t_program *program, pthread_mutex_t *forks);
int		dead_lock(t_philo *philo);
int		improved_usleep(size_t ms, t_monitor_program *monitorer);
int		ft_atoi(const char *nptr);
int		str_isdigit(char *str);
int		check_valid(char **av);
int		ft_isdigit(int c);
int	dead_check(t_monitor_program *monitorer);

#endif
