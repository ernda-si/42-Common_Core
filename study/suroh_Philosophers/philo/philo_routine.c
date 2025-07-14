/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suroh <suroh@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:15:02 by suroh             #+#    #+#             */
/*   Updated: 2025/04/06 20:03:58 by suroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	i_will_eat(t_philo *philo, t_monitor_data *mdata)
{
	pthread_mutex_lock(philo->right_fork);
	print_msg("has taken a fork", philo, mdata->shared, philo->id);
	if (mdata->shared->number_of_philosophers == 1)
	{
		upgraded_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_msg("has taken a fork", philo, mdata->shared, philo->id);
	philo->is_eating_now = 1;
	print_msg("is eating", philo, mdata->shared, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->time_of_last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	upgraded_usleep(philo->time_to_eat);
	philo->is_eating_now = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

static void	i_will_sleep(t_philo *philo, t_monitor_data *mdata)
{
	print_msg("is sleeping", philo, mdata->shared, philo->id);
	upgraded_usleep(philo->time_to_sleep);
}

static void	i_will_think(t_philo *philo, t_monitor_data *data)
{
	print_msg("is thinking", philo, data->shared, philo->id);
}

int	yes_i_am_not_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->is_dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	return (pthread_mutex_unlock(philo->dead_lock), 0);
}

void	*philo_routine(void *arg)
{
	t_monitor_data	*mdata;
	t_philo			*this_philo;

	mdata = (t_monitor_data *)arg;
	this_philo = &mdata->philos[mdata->philo_idx];
	if (this_philo->id % 2 == 0)
		upgraded_usleep(1);
	while (0 == yes_i_am_not_dead(this_philo))
	{
		i_will_eat(this_philo, mdata);
		i_will_sleep(this_philo, mdata);
		i_will_think(this_philo, mdata);
	}
	return (arg);
}
