/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 02:39:51 by eve               #+#    #+#             */
/*   Updated: 2025/08/27 02:40:06 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	upgraded_usleep(size_t ms)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < ms)
		usleep(500);
	return (0);
}
