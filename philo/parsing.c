/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 03:13:38 by ernda-si          #+#    #+#             */
/*   Updated: 2025/08/28 14:28:53 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	if (n <= 0 || n > 200 || str_isdigit(av[1]) == -1)
		return (error_msg("First arg must be 200 > integer > 0\n", 36));
	n = ft_atoi(av[2]);
	if (n <= 0 || str_isdigit(av[2]) == -1)
		return (error_msg("Second arg must be a integer > 0\n", 33));
	n = ft_atoi(av[3]);
	if (n <= 0 || str_isdigit(av[3]) == -1)
		return (error_msg("Third arg must be a integer > 0\n", 32));
	n = ft_atoi(av[4]);
	if (n <= 0 || str_isdigit(av[4]) == -1)
		return (error_msg("Fourth arg must be a integer > 0\n", 33));
	if (av[5] && (ft_atoi(av[5]) < 0 || str_isdigit(av[5]) == -1))
		return (error_msg
			("Fifth arg must be a integer > 0\n", 32));
	return (0);
}
