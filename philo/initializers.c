/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:54:42 by ernda-si          #+#    #+#             */
/*   Updated: 2025/08/28 14:29:09 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(char **av, t_philo *philos, t_program *program,
		pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].eaten_meals = 0;
		philos[i].t_die = ft_atoi(av[2]);
		philos[i].t_eat = ft_atoi(av[3]);
		philos[i].t_sleep = ft_atoi(av[4]);
		philos[i].t_last_meal = get_current_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].dead = &program->one_dead_flag;
		philos[i].r_fork = &forks[i];
		philos[i].l_fork = &forks[i - 1];
		if (i == 0)
			philos[i].l_fork = &forks[program->max_philos - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int max_philos)
{
	int	i;

	i = -1;
	while (++i < max_philos)
		pthread_mutex_init(&forks[i], NULL);
}

void	init_program(char **av, t_program *program, t_philo *philos)
{
	program->one_dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	program->t_start = get_current_time();
	program->max_philos = ft_atoi(av[1]);
	program->n_still_eat = -1;
	if (av[5])
		program->n_still_eat = ft_atoi(av[5]);
}
