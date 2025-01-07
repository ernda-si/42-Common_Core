/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_tired.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:37:36 by ernda-si          #+#    #+#             */
/*   Updated: 2025/01/07 18:11:11 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_num(t_stacks **head)
{
	t_stacks	*node;
	int			min;

	min = min_n(*head) * -1;
	node = (*head);
	while (node)
	{
		node -> number += min;
		node = node -> next;
	}
	return ;
}

t_stacks	*last_node(t_stacks *head)
{
	t_stacks	*temp;
	int			size;

	size = lst_size(head);
	temp = head;
	while (--size)
		temp = temp -> next;
	return (temp);
}

void	error_all(t_stacks *head, char **matrix)
{
	free_all (head, matrix);
	write (2, "Error\n", 6);
	exit (1);
}

void	big_sort(t_stacks **head, t_stacks **head_b)
{
	while (lst_size(*head) != 3)
	{
		if ((*head)-> number == min_n(*head))
			push_b(head_b, head);
		else if ((*head)-> next -> next -> number == min_n(*head)
			|| (*head)-> next -> next -> next -> number == min_n(*head)
			|| last_node(*head)-> number == min_n(*head))
			rrotate_a(head);
		else
			rotate_a(head);
	}
	medium_sort(head);
	while (*head_b)
		push_a(head, head_b);
}

int	num_valid(char const *str)
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
		if (!(num * signal >= -2147483648 && num * signal <= 2147483647))
			return (0);
	}
	return (1);
}
