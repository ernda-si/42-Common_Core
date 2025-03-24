/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:39:28 by ernda-si          #+#    #+#             */
/*   Updated: 2025/01/07 18:07:04 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_checker(char *str)
{
	int	i;
	// int	len;

	// len = ft_strlen(str);
	i = 0;
	if (!str || !str[i] || !check_num(str))
		return (1);
	if ((str[i] == '-' || str[i] == '+')
		&& str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	else if (str[i] == '-' && str[i + 1] <= '0' && str[i + 1] >= '9')
		return (1);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		i++;
	if (str[i] < '0' && str[i] > '9' && str[i])
		return (1);
	if (!str[i])
		return (0);
	return (1);
}

int	ft_atoi(char const *str)
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

t_stacks	*create_node(int new_data)
{
	t_stacks	*new_node;

	new_node = (t_stacks *)malloc (sizeof(t_stacks));
	if (!new_node)
		exit(0);
	new_node -> number = new_data;
	new_node -> next = NULL;
	return (new_node);
}

t_stacks	*lstadd(int new_data, t_stacks *start)
{
	t_stacks	*end;
	t_stacks	*node;

	node = create_node(new_data);
	if (!start)
	{
		start = node;
		return (start);
	}
	end = start;
	while (end -> next)
		end = end -> next;
	end -> next = node;
	return (start);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i] && (str[i] < '0' || str[i] > '9'))
		i++;
	if (str[i] && str[i] >= '0' && str[i] <= '9')
		return (1);
	return (0);
}
