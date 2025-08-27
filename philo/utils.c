/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:37:52 by suroh             #+#    #+#             */
/*   Updated: 2025/08/27 03:39:21 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msg(char *str, t_philo *philo, t_program *program, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - program->t_start;
	if (0 == dead_lock(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	kill_all(char *str, t_program *program, pthread_mutex_t *forks)
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
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (++i < program->max_philos)
		pthread_mutex_destroy(&forks[i]);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		signal;
	long	num;

	i = 0;
	signal = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
			num *= 10;
			num += str[i++] - '0';
	}
	if (num * signal >= -2147483648 && num * signal <= 2147483647)
			return (signal * num);
	return (0);
}
