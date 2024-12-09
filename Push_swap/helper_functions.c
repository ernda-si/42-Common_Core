/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:19:59 by ernda-si          #+#    #+#             */
/*   Updated: 2024/12/09 17:33:59 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_n(struct Stacks *head)
{
	struct Stacks	*big_num;
	struct Stacks	*temp;
	int				max;

	big_num = head;
	temp = create_node(head->number);
	temp->next = head->next;
	while (big_num)
	{
		if ((temp -> number) < (big_num -> number) && big_num)
			temp -> number = big_num -> number;
		big_num = big_num -> next;
	}
	max = temp->number;
	free(temp);
	return (max);
}

int	min_n(struct Stacks *head)
{
	struct Stacks	*small_num;
	struct Stacks	*temp;
	int				min;

	small_num = head;
	temp = create_node(head->number);
	temp->next = head->next;
	while (small_num)
	{
		if ((temp -> number) > (small_num -> number) && small_num)
			temp -> number = small_num -> number;
		small_num = small_num -> next;
	}
	min = temp->number;
	free(temp);
	return (min);
}

int	lst_size(struct Stacks *head)
{
	int	size;

	size = 0;
	while (head)
	{
		head = head -> next;
		size++;
	}
	return (size);
}

int	has_num(struct Stacks *head, int num)
{
	struct Stacks	*check;

	check = head;
	while (check)
	{
		if (check -> number == num)
			return (1);
		check = check -> next;
	}
	return (0);
}

void	free_lst(struct Stacks *head, char **matrix)
{
	struct Stacks	*temp;
	struct Stacks	*temp2;
	int				i;
	int				size;

	size = lst_size(head) + 1;
	i = 0;
	temp = head;
	temp2 = head;
	while (--size && head)
	{
		temp = temp2;
		while (temp)
			temp = temp -> next;
		head = temp;
		free(head);
	}
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	// free(head);
	return ;
}
