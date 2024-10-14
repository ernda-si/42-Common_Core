/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:54:33 by ernda-si          #+#    #+#             */
/*   Updated: 2024/10/14 15:09:31 by ernda-si         ###   ########.fr       */
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
		return ;
	new_node = create_node((*head_b)-> number);
	new_node -> next = *head;
	*head = new_node;

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
		return ;
	new_node = create_node((*head)-> number);
	if (!new_node)
		return ;
	new_node -> next = *head_b;
	*head_b = new_node;

	temp = *head;
	*head = (*head)-> next;
	free(temp);
	write (1, "pb\n", 3);
}
