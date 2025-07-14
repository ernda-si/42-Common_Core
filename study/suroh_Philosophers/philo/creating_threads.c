/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suroh <suroh@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:20:21 by suroh             #+#    #+#             */
/*   Updated: 2025/04/07 12:24:09 by suroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_monitor_thread(t_shared_data *data,
								pthread_mutex_t *forks,
								t_monitor_data *mdata,
								pthread_t *monitor_thread)
{
	mdata->philos = data->philos;
	mdata->shared = data;
	if (pthread_create(monitor_thread, NULL, &monitor, (void *)mdata) != 0)
		destroy_all("Error while attempting to create Monitor Thread",
			data, forks);
}

static void	create_philos_threads(t_shared_data *data,
								pthread_mutex_t *forks,
								t_monitor_data *philo_data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo_data[i].philos = data->philos;
		philo_data[i].shared = data;
		philo_data[i].philo_idx = i;
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine,
				(void *)&philo_data[i]) != 0)
			destroy_all("Error while attempting to create Philos Thread",
				data, forks);
		i++;
	}
}

static void	join_all_threads(t_shared_data *data,
								pthread_mutex_t *forks,
								pthread_t monitor_thread)
{
	int	i;

	i = 0;
	if (pthread_join(monitor_thread, NULL) != 0)
		destroy_all("Error while attempting joining threads", data, forks);
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			destroy_all("Error while attempting joining threads", data, forks);
		i++;
	}
}

int	create_threads(t_shared_data *data, pthread_mutex_t *forks)
{
	t_monitor_data	philo_data[MAX_NUMBER_OF_PHILOS];
	t_monitor_data	monitor_data;
	pthread_t		monitor_thread;

	if (data->number_of_philosophers > 200)
		destroy_all("Too many philosophers for static allocation", data, forks);
	monitor_data.philos = data->philos;
	monitor_data.shared = data;
	create_monitor_thread(data, forks, &monitor_data, &monitor_thread);
	create_philos_threads(data, forks, philo_data);
	join_all_threads(data, forks, monitor_thread);
	return (0);
}
