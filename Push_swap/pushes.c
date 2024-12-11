/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:54:33 by ernda-si          #+#    #+#             */
/*   Updated: 2024/12/11 12:09:02 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa (push a): Take the first element at the top of b
//and put it at the top of a.
// Do nothing if b is empty.
void	push_a(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks	*temp;

	if (!head_b || !*head_b)
		return ;
	temp = *head_b;
	*head_b = (*head_b)-> next;
	if (!head)
		*head = temp;
	else
	{
		temp -> next = *head;
		*head = temp;
	}
	write (1, "pa\n", 3);
}

// pb (push b): Take the first element at the top of a
//and put it at the top of b.
// Do nothing if a is empty.
void	push_b(struct Stacks **head_b, struct Stacks **head)
{
	struct Stacks	*temp;

	if (!head || !*head)
		return ;
	temp = *head;
	*head = (*head)-> next;
	if (!head_b)
		*head_b = temp;
	else
	{
		temp -> next = *head_b;
		*head_b = temp;
	}
	write (1, "pb\n", 3);
}
