/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:22:58 by ernda-si          #+#    #+#             */
/*   Updated: 2025/08/28 15:35:29 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	dead(t_philo *philo, size_t t_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->t_last_meal >= t_die
		&& philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	dead_check(t_monitor_program *monitorer)
{
	int	i;

	i = -1;
	while (++i < monitorer->shared->max_philos)
	{
		if (1 == dead(&monitorer->philos[i], monitorer->philos[i].t_die))
		{
			print_task(RED"died"RESET, &monitorer->philos[i], monitorer->shared,
				monitorer->philos[i].id);
			pthread_mutex_lock(&(monitorer->shared->dead_lock));
			*monitorer->philos[i].dead = 1;
			pthread_mutex_unlock(&(monitorer->shared->dead_lock));
			return (1);
		}
	}
	return (0);
}

static int	done_eating(t_monitor_program *monitorer)
{
	int	ate;
	int	i;

	ate = 0;
	if (monitorer->shared->n_still_eat == -1)
		return (0);
	i = -1;
	while (++i < monitorer->shared->max_philos)
	{
		pthread_mutex_lock(monitorer->philos[i].meal_lock);
		if (monitorer->philos[i].eaten_meals
			>= monitorer->shared->n_still_eat)
			ate++;
		pthread_mutex_unlock(monitorer->philos[i].meal_lock);
	}
	if (ate == monitorer->shared->max_philos)
		return (1);
	return (0);
}

static int	eat_check(t_monitor_program *monitorer)
{
	if (done_eating(monitorer))
	{
		pthread_mutex_lock(&(monitorer->shared->dead_lock));
		monitorer->shared->one_dead_flag = 1;
		pthread_mutex_unlock(&(monitorer->shared->dead_lock));
		pthread_mutex_lock(&(monitorer->shared->write_lock));
		printf(GREEN"All philosophers ate %d times!\n"RESET,
			monitorer->shared->n_still_eat);
		pthread_mutex_unlock(&(monitorer->shared->write_lock));
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_monitor_program	*monitorer;

	monitorer = (t_monitor_program *)arg;
	while (1)
		if (dead_check(monitorer) == 1 || eat_check(monitorer) == 1)
			break ;
	return (arg);
}
