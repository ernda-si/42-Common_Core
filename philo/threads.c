/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:20:21 by ernda-si          #+#    #+#             */
/*   Updated: 2025/08/28 14:28:36 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	create_monitor_thread(t_program *program, pthread_mutex_t *forks,
			t_monitor_program *monitorer, pthread_t *monitor_thread)
{
	monitorer->philos = program->philos;
	monitorer->shared = program;
	if (pthread_create(monitor_thread, NULL, &monitor, (void *)monitorer) != 0)
		kill_all(RED"Monitor thread error creation!\n"RESET,
			program, forks);
}

static void	create_philos_threads(t_program *program, pthread_mutex_t *forks,
			t_monitor_program *philo_program)
{
	int	i;

	i = 0;
	while (i < program->max_philos)
	{
		philo_program[i].philos = program->philos;
		philo_program[i].shared = program;
		philo_program[i].philo_idx = i;
		if (pthread_create(&program->philos[i].thread, NULL, &routine,
				(void *)&philo_program[i]) != 0)
			kill_all(RED"Philosophers thread creation error\n!"RESET,
				program, forks);
		i++;
	}
}

static void	join_all_threads(t_program *program, pthread_mutex_t *forks,
			pthread_t monitor_thread)
{
	int	i;

	i = 0;
	if (pthread_join(monitor_thread, NULL) != 0)
		kill_all(RED"Joining threads error!\n"RESET, program, forks);
	while (i < program->max_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			kill_all(RED"Joining threads error!\n"RESET, program, forks);
		i++;
	}
}

int	create_threads(t_program *program, pthread_mutex_t *forks)
{
	t_monitor_program	philo_program[200];
	t_monitor_program	monitor_program;
	pthread_t			monitor_thread;

	if (program->max_philos > 200)
		kill_all("Philosophers exceeded the amount limit!\n", program, forks);
	monitor_program.philos = program->philos;
	monitor_program.shared = program;
	create_monitor_thread(program, forks, &monitor_program, &monitor_thread);
	create_philos_threads(program, forks, philo_program);
	join_all_threads(program, forks, monitor_thread);
	return (0);
}
