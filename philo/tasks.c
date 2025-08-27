/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 03:11:23 by eve               #+#    #+#             */
/*   Updated: 2025/08/27 03:23:23 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_sleep(t_philo *philo, t_monitor_program *monitorer)
{
	print_msg("is sleeping", philo, monitorer->shared, philo->id);
	upgraded_usleep(philo->t_sleep);
}

void	think(t_philo *philo, t_monitor_program *program)
{
	print_msg("is thinking", philo, program->shared, philo->id);
}

void	eat(t_philo *philo, t_monitor_program *monitorer)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken a fork", philo, monitorer->shared, philo->id);
	if (monitorer->shared->max_philos == 1)
	{
		upgraded_usleep(philo->t_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_msg("has taken a fork", philo, monitorer->shared, philo->id);
	philo->eating = 1;
	print_msg("is eating", philo, monitorer->shared, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->t_last_meal = get_current_time();
	philo->eaten_meals++;
	pthread_mutex_unlock(philo->meal_lock);
	upgraded_usleep(philo->t_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
