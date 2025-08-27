/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 03:13:38 by eve               #+#    #+#             */
/*   Updated: 2025/08/27 03:30:44 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	check_valid(char **av)
{
	int	n;

	n = ft_atoi(av[1]);
	if (n > 200)
		return (error_msg("Exceeded Maximum Number of Philosophers\n", 40));
	if (n <= 0 || str_isdigit(av[1]) == -1)
		return (error_msg("Invalid value for philosophers number\n", 38));
	n = ft_atoi(av[2]);
	if (n <= 0 || str_isdigit(av[2]) == -1)
		return (error_msg("Invalid value for time to die\n", 30));
	n = ft_atoi(av[3]);
	if (n <= 0 || str_isdigit(av[3]) == -1)
		return (error_msg("Invalid value for time to eat\n", 30));
	n = ft_atoi(av[4]);
	if (n <= 0 || str_isdigit(av[4]) == -1)
		return (error_msg("Invalid value for time to sleep\n", 32));
	if (av[5] && (ft_atoi(av[5]) < 0 || str_isdigit(av[5]) == -1))
		return (error_msg
			("Invalid value for number of times each philosopher must eat\n",
				60));
	return (0);
}
