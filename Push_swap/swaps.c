/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:53:37 by ernda-si          #+#    #+#             */
/*   Updated: 2025/01/07 17:34:31 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	swap_a(t_stacks *head)
{
	t_stacks	temp;

	if (!head || !head -> next)
		exit(0);
	temp . number = head -> number;
	head -> number = head -> next -> number;
	head -> next -> number = temp . number;
	write(1, "sa\n", 3);
}

// sa (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	swap_b(t_stacks *head_b)
{
	t_stacks	temp_b;

	if (!head_b || !head_b -> next)
		return ;
	temp_b . number = head_b -> number;
	head_b -> number = head_b -> next -> number;
	head_b -> next -> number = temp_b . number;
	write(1, "sb\n", 3);
}

// ss : sa and sb at the same time.
void	swap_swap(t_stacks *head, t_stacks *head_b)
{
	t_stacks	temp;

	if (!head || !head_b || !head -> next || !head_b -> next)
		exit(0);
	temp . number = head -> number;
	head -> number = head -> next -> number;
	head -> next -> number = temp . number;
	temp . number = head_b -> number;
	head_b -> number = head_b -> next -> number;
	head_b -> next -> number = temp . number;
	write(1, "ss\n", 3);
}
