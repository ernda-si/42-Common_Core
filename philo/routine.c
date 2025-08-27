/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:15:02 by suroh             #+#    #+#             */
/*   Updated: 2025/08/27 13:52:25 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dead_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	return (pthread_mutex_unlock(philo->dead_lock), 0);
}

void	*routine(void *arg)
{
	t_monitor_program	*monitorer;
	t_philo				*current;

	monitorer = (t_monitor_program *)arg;
	current = &monitorer->philos[monitorer->philo_idx];
	if (current->id % 2 == 0)
		improved_usleep(1);
	while (0 == dead_lock(current))
		(eat(current, monitorer), to_sleep(current, monitorer), \
		 think(current, monitorer));
	return (arg);
}
