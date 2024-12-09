/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_tired.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:37:36 by ernda-si          #+#    #+#             */
/*   Updated: 2024/12/09 17:11:06 by ernda-si         ###   ########.fr       */
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
	struct Stacks	*temp_2;

	temp_2 = head;
	while (temp_2)
		temp_2 = temp_2 -> next;
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
