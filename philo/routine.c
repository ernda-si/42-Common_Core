/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:15:02 by ernda-si          #+#    #+#             */
/*   Updated: 2025/08/28 15:34:42 by ernda-si         ###   ########.fr       */
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
		improved_usleep(1, monitorer);
	while (dead_lock(current) == 0)
		(eat(current, monitorer), to_sleep(current, monitorer),
			think(current, monitorer));
	return (arg);
}
