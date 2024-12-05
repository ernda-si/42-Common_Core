/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:39:28 by ernda-si          #+#    #+#             */
/*   Updated: 2024/12/05 17:16:54 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_checker(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (!str || !*str)
		return (write(2, "Error\n", 6));
	if (str[i] != '-' && len > 10)
		return (write(2, "Error\n", 6));
	if (str[i] == '-' && str[i + 1] >= 48 && str[i + 1] <= 57)
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		i++;
	if (str[i] < '0' && str[i] > '9' && str[i])
		return (write(2, "Error\n", 6));
	if (!str[i])
		return (1);
	return (write(2, "Error\n", 6));
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
	write(2, "Error\n", 6);
	exit(0);
}

struct Stacks	*create_node(int new_data)
{
	struct Stacks	*new_node;

	new_node = (struct Stacks *)malloc (sizeof(struct Stacks));
	if (!new_node)
		exit(0);
	new_node -> number = new_data;
	new_node -> next = NULL;
	return (new_node);
}

struct Stacks	*lstadd(int new_data, struct Stacks *start)
{
	struct Stacks	*end;
	struct Stacks	*node;

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
