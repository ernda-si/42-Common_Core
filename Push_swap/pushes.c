/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:54:33 by ernda-si          #+#    #+#             */
/*   Updated: 2025/01/07 17:34:18 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa (push a): Take the first element at the top of b
//and put it at the top of a.
// Do nothing if b is empty.
void	push_a(t_stacks **head, t_stacks **head_b)
{
	t_stacks	*temp;

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
void	push_b(t_stacks **head_b, t_stacks **head)
{
	t_stacks	*temp;

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
