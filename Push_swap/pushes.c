/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:54:33 by ernda-si          #+#    #+#             */
/*   Updated: 2024/10/01 13:27:12 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa (push a): Take the first element at the top of b
//and put it at the top of a.
// Do nothing if b is empty.
void	push_a(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks	*new_node;
	struct Stacks	*temp;

	if (!*head_b)
		exit(0);
	new_node = create_node ((*head)-> number);
	new_node -> next = (*head)-> next;
	(*head)-> next = new_node;
	(*head)-> number = (*head_b)-> number;
	temp = *head_b;
	*head_b = (*head_b)-> next;
	free(temp);
	write (1, "pa\n", 3);
}

// pb (push b): Take the first element at the top of a
//and put it at the top of b.
// Do nothing if a is empty.
void	push_b(struct Stacks **head_b, struct Stacks **head)
{
	struct Stacks	*new_node;
	struct Stacks	*temp;

	if (!*head)
		exit(0);
	else if (!*head_b)
	{
		new_node = create_node((*head)-> number);
		(*head_b) = new_node;
	}
	else
	{
		new_node = create_node((*head_b)-> number);
		new_node -> next = (*head_b)-> next;
		(*head_b)-> next = new_node;
		(*head_b)-> number = (*head)-> number;
	}
	temp = *head;
	*head = (*head)-> next;
	free(temp);
	write (1, "pb\n", 3);
}
