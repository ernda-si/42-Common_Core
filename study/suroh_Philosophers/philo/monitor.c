/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suroh <suroh@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:47:08 by suroh             #+#    #+#             */
/*   Updated: 2025/04/07 12:28:50 by suroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	he_is_gone(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->time_of_last_meal >= time_to_die
		&& philo->is_eating_now == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

static int	is_he_dead(t_monitor_data *mdata)
{
	int	i;

	i = -1;
	while (++i < mdata->shared->number_of_philosophers)
	{
		if (1 == he_is_gone(&mdata->philos[i], mdata->philos[i].time_to_die))
		{
			print_msg("died", &mdata->philos[i], mdata->shared,
				mdata->philos[i].id);
			pthread_mutex_lock(&(mdata->shared->dead_lock));
			*mdata->philos[i].is_dead = 1;
			pthread_mutex_unlock(&(mdata->shared->dead_lock));
			return (1);
		}
	}
	return (0);
}

static int	all_philos_ate_enough(t_monitor_data *mdata)
{
	int	i;
	int	finished_eating;

	finished_eating = 0;
	if (mdata->shared->number_of_times_philo_must_eat == -1)
		return (0);
	i = -1;
	while (++i < mdata->shared->number_of_philosophers)
	{
		pthread_mutex_lock(mdata->philos[i].meal_lock);
		if (mdata->philos[i].meals_eaten
			>= mdata->shared->number_of_times_philo_must_eat)
			finished_eating++;
		pthread_mutex_unlock(mdata->philos[i].meal_lock);
	}
	if (finished_eating == mdata->shared->number_of_philosophers)
		return (1);
	return (0);
}

static int	did_all_eat(t_monitor_data *mdata)
{
	if (all_philos_ate_enough(mdata))
	{
		pthread_mutex_lock(&(mdata->shared->dead_lock));
		mdata->shared->one_dead_flag = 1;
		pthread_mutex_unlock(&(mdata->shared->dead_lock));
		pthread_mutex_lock(&(mdata->shared->write_lock));
		printf("\n\033[0;32m✓ SIMULATION SUCCESSFUL:");
		printf("All philosophers ate %d times!\033[0m\n",
			mdata->shared->number_of_times_philo_must_eat);
		pthread_mutex_unlock(&(mdata->shared->write_lock));
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_monitor_data	*mdata;

	mdata = (t_monitor_data *)arg;
	while (1)
		if (is_he_dead(mdata) == 1 || did_all_eat(mdata) == 1)
			break ;
	return (arg);
}
