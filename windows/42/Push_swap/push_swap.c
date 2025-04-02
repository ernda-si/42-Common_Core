/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/02 13:55:28 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stacks **head)
{
	if ((*head)-> number > (*head)-> next -> number)
		swap_a(*head);
	else
		return ;
}

void	medium_sort(t_stacks **head)
{
	int	first;
	int	second;
	int	third;

	first = (*head)-> number;
	second = (*head)-> next -> number;
	third = (*head)-> next -> next -> number;
	if (first < second && second > third && third > first)
		return (swap_a(*head), rotate_a(head));
	else if (first > second && second < third && third > first)
		return (swap_a(*head));
	else if (first < second && second > third && third < first)
		return (rrotate_a(head));
	else if (first > second && second > third)
		return (rotate_a(head), swap_a(*head));
	else if (first > second && second < third)
		return (rotate_a(head));
}

void	sort(t_stacks **head, t_stacks **head_b)
{
	int	exp;
	int	temp;
	int	size;

	temp = 0;
	index_nums(*head);
	exp = bin_count(max_n(*head));
	while (temp != exp)
	{
		size = lst_size(*head);
		while (size)
		{
			if (((*head)-> index >> temp & 1) == 0)
				push_b(head_b, head);
			else
				rotate_a(head);
			if (!bin_left(*head, temp))
				break ;
			size--;
		}
		while ((*head_b))
			push_a(head, head_b);
		temp++;
	}
}

int	main(int ac, char *av[])
{
	(void) ac;
	if (ac < 2)
		return (0);
	else if (ac > 2)
		args_parse(ac, av);
	else if (ac == 2)
		str_parse(ac, av);
	return (0);
}
