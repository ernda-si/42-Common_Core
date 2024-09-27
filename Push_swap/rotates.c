/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:55:03 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/27 17:26:16 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a(struct Stacks **head)
{
	struct Stacks	*end;
	struct Stacks	*end_node;
	struct Stacks	*temp;

	if (!*head || !(*head)-> next)
		exit(0);
	end_node = create_node((*head)-> number);
	end = *head;
	while (end -> next)
		end = end -> next;
	end -> next = end_node;
	temp = *head;
	*head = (*head)-> next;
	free(temp);
	write (1, "ra\n", 3);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rotate_b(struct Stacks **head_b)
{
	struct Stacks	*end;
	struct Stacks	*end_node;
	struct Stacks	*temp;

	if (!*head_b || !(*head_b)-> next)
		exit(0);
	end_node = create_node((*head_b)-> number);
	end = *head_b;
	while (end -> next)
		end = end -> next;
	end -> next = end_node;
	temp = *head_b;
	*head_b = (*head_b)-> next;
	free(temp);
	write (1, "rb\n", 3);
}

// rr : ra and rb at the same time.
void	rotate_ab(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks	*end;
	struct Stacks	*end_node;
	struct Stacks	*temp;

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
