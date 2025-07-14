/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suroh <suroh@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:32:10 by suroh             #+#    #+#             */
/*   Updated: 2025/04/05 21:37:34 by suroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			minuscount;
	long int	value;

	i = 0;
	value = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	minuscount = 1;
	if (nptr[i] == 45)
	{
		minuscount = -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	while (ft_isdigit(nptr[i]) == 1)
	{
		value = value * 10 + (nptr[i] - '0');
		i++;
	}
	return ((value * minuscount));
}
