/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suroh <suroh@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:54:42 by suroh             #+#    #+#             */
/*   Updated: 2025/04/06 19:20:06 by suroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_shared_data(t_shared_data *data, t_philo *philos, char **argv)
{
	data->one_dead_flag = 0;
	data->philos = philos;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	data->starting_time = get_current_time();
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->number_of_times_philo_must_eat = -1;
	if (argv[5])
		data->number_of_times_philo_must_eat = ft_atoi(argv[5]);
}

void	init_forks(pthread_mutex_t *forks, int number_of_philosophers)
{
	int	i;

	i = -1;
	while (++i < number_of_philosophers)
		pthread_mutex_init(&forks[i], NULL);
}

void	init_philos(t_philo *philos, t_shared_data *data,
		pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].is_eating_now = 0;
		philos[i].meals_eaten = 0;
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		philos[i].time_of_last_meal = get_current_time();
		philos[i].write_lock = &data->write_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].is_dead = &data->one_dead_flag;
		philos[i].right_fork = &forks[i];
		philos[i].left_fork = &forks[i - 1];
		if (i == 0)
			philos[i].left_fork = &forks[data->number_of_philosophers - 1];
	}
}
