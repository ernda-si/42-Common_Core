/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suroh <suroh@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:52:08 by suroh             #+#    #+#             */
/*   Updated: 2025/04/06 18:30:42 by suroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

static int	error_msg(char *msg, int len)
{
	int	return_value;

	return_value = write(2, msg, len);
	(void)return_value;
	return (-1);
}

static int	check_valid(char **argv)
{
	int	n;

	n = ft_atoi(argv[1]);
	if (n > MAX_NUMBER_OF_PHILOS)
		return (error_msg("Exceeded Maximum Number of Philosophers\n", 40));
	if (n <= 0 || str_isdigit(argv[1]) == -1)
		return (error_msg("Invalid value for philosophers number\n", 38));
	n = ft_atoi(argv[2]);
	if (n <= 0 || str_isdigit(argv[2]) == -1)
		return (error_msg("Invalid value for time to die\n", 30));
	n = ft_atoi(argv[3]);
	if (n <= 0 || str_isdigit(argv[3]) == -1)
		return (error_msg("Invalid value for time to eat\n", 30));
	n = ft_atoi(argv[4]);
	if (n <= 0 || str_isdigit(argv[4]) == -1)
		return (error_msg("Invalid value for time to sleep\n", 32));
	if (argv[5] && (ft_atoi(argv[5]) < 0 || str_isdigit(argv[5]) == -1))
		return (error_msg
			("Invalid value for number of times each philosopher must eat\n",
				60));
	return (0);
}

int	main(int argc, char **argv)
{
	t_shared_data	shared_data;
	t_philo			philos[MAX_NUMBER_OF_PHILOS];
	pthread_mutex_t	forks[MAX_NUMBER_OF_PHILOS];
	int				return_val;

	if (argc != 5 && argc != 6)
	{
		return_val = write(2, "Wrong argument count\n", 22);
		(void)return_val;
		return (-1);
	}
	if (check_valid(argv) == -1)
		return (-1);
	init_shared_data(&shared_data, philos, argv);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &shared_data, forks, argv);
	create_threads(&shared_data, forks);
	destroy_all(NULL, &shared_data, forks);
	return (0);
}
