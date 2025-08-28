/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:52:08 by ernda-si          #+#    #+#             */
/*   Updated: 2025/08/28 14:29:01 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_philo			philos[200];
	pthread_mutex_t	forks[200];
	t_program		program;

	if (ac != 5 && ac != 6)
		return (write(2, "Invalid amount of arguments\n", 29), -1);
	if (check_valid(av) == -1)
		return (-1);
	init_program(av, &program, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(av, philos, &program, forks);
	create_threads(&program, forks);
	kill_all(NULL, &program, forks);
	return (0);
}
