/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:19:59 by ernda-si          #+#    #+#             */
/*   Updated: 2025/01/07 17:37:52 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_n(t_stacks *head)
{
	t_stacks	*big_num;
	t_stacks	*temp;
	int			max;

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

int	min_n(t_stacks *head)
{
	t_stacks	*small_num;
	t_stacks	*temp;
	int			min;

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

int	lst_size(t_stacks *head)
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

int	has_num(t_stacks *head, int num)
{
	t_stacks	*check;

	check = head;
	while (check)
	{
		if (check -> number == num)
			return (1);
		check = check -> next;
	}
	return (0);
}

void	free_all(t_stacks *head, char **matrix)
{
	t_stacks	*temp;
	int			i;

	i = -1;
	while (head)
	{
		temp = head;
		head = head -> next;
		free(temp);
	}
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
	return ;
}
