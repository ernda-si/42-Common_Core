/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_tired.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:37:36 by ernda-si          #+#    #+#             */
/*   Updated: 2024/12/12 18:39:18 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_num(struct Stacks **head)
{
	struct Stacks	*node;
	int				min;

	min = min_n(*head) * -1;
	printf("min number: %d\n", min);
	node = (*head);
	while (node)
	{
		node -> number += min;
		node = node -> next;
	}
	return ;
}

void	print_list(struct Stacks *head)
{
	struct Stacks	*temp;
	int				i;

	i = 0;
	temp = head;
	while (temp)
	{
		printf("lst[%d]: %d   ", i++ ,temp -> number);
		temp = temp -> next;
	}
	printf("\n");
}

struct Stacks	*last_node(struct Stacks *head)
{
	struct Stacks	*temp;
	int				size;

	size = lst_size(head);
	temp = head;
	while (--size)
		temp = temp -> next;
	return (temp);
}

void	error_all(struct Stacks *head, char **matrix)
{
	if (head && matrix)
		free_all (head, matrix);
	exit(1);
}

void	big_sort(struct Stacks **head, struct Stacks **head_b)
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
		if (verify(*head))
			return ;
	}
	medium_sort(head);
	while (*head_b)
		push_a(head, head_b);
}
