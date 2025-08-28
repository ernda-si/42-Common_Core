/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 02:39:51 by ernda-si          #+#    #+#             */
/*   Updated: 2025/08/28 15:33:42 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_current_time(void)
{
	int				return_value;
	size_t			result;
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		return_value = write(2, "gettimeofday() function error\n", 30);
		(void)return_value;
	}
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

int	improved_usleep(size_t ms, t_monitor_program *monitorer)
{
	size_t	start;

	start = get_current_time();
	if (dead_check(monitorer) == 1)
		return (1);
	while ((get_current_time() - start) < ms)
		usleep(500);
	return (0);
}
