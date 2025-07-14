/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suroh <suroh@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:37:52 by suroh             #+#    #+#             */
/*   Updated: 2025/04/06 18:13:52 by suroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(char *str, t_philo *philo, t_shared_data *data, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - data->starting_time;
	if (0 == yes_i_am_not_dead(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	upgraded_usleep(size_t ms)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < ms)
		usleep(500);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;
	size_t			result;
	int				return_value;

	if (gettimeofday(&time, NULL) == -1)
	{
		return_value = write(2, "gettimeofday() function error\n", 30);
		(void)return_value;
	}
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

void	destroy_all(char *str, t_shared_data *data, pthread_mutex_t *forks)
{
	int	i;
	int	ret;

	i = -1;
	if (str)
	{
		ret = write(2, str, ft_strlen(str));
		(void)ret;
		ret = write(2, "\n", 1);
		(void)ret;
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&forks[i]);
}
