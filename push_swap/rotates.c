/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:55:03 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/02 13:56:20 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a(t_stacks **head)
{
	t_stacks	*start;
	t_stacks	*end;

	if (!*head)
		return ;
	start = *head;
	*head = (*head)-> next;
	start -> next = NULL;
	end = *head;
	while (end -> next)
		end = end -> next;
	end -> next = start;
	write (1, "ra\n", 3);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rotate_b(t_stacks **head_b)
{
	t_stacks	*start;
	t_stacks	*end;

	if (!*head_b)
		return ;
	start = *head_b;
	*head_b = (*head_b)-> next;
	start -> next = NULL;
	end = *head_b;
	while (end -> next)
		end = end -> next;
	end -> next = start;
	write (1, "ra\n", 3);
}

// rr : ra and rb at the same time.
void	rotate_ab(t_stacks **head, t_stacks **head_b)
{
	t_stacks	*end;
	t_stacks	*end_node;
	t_stacks	*temp;

	if (!*head_b || !*head || !(*head_b)-> next || !(*head)-> next)
		exit(0);
	end_node = create_node((*head_b)-> number);
	end = *head_b;
	while (end -> next)
		end = end -> next;
	end -> next = end_node;
	temp = *head_b;
	*head_b = (*head_b)-> next;
	free (temp);
	end_node = create_node((*head)-> number);
	end = *head;
	while (end -> next)
		end = end -> next;
	end -> next = end_node;
	temp = *head;
	*head = (*head)-> next;
	free(temp);
	write (1, "rr\n", 3);
}
