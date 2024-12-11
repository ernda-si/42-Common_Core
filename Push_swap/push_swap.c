/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/12/11 17:56:38 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(struct Stacks **head)
{
	if ((*head)-> number > (*head)-> next -> number)
		swap_a(*head);
	else
		return ;
}

void	medium_sort(struct Stacks **head)
{
	int	first;
	int	second;
	int	third;

	first = (*head)-> number;
	second = (*head)-> next -> number;
	third = (*head)-> next -> next -> number;
	if (first < second && second > third && third > first)
		return (swap_a(*head), rotate_a(head));
	else if (first > second && second < third && third > first)
		return (swap_a(*head));
	else if (first < second && second > third && third < first)
		return (rrotate_a(head));
	else if (first > second && second > third)
		return (rotate_a(head), swap_a(*head));
	else if (first > second && second < third)
		return (rotate_a(head));
}

void	sort(struct Stacks **head, struct Stacks **head_b)
{
	int	exp;
	int	temp;
	int	size;

	temp = 0;
	if (min_n(*head) < 0)
		index_num(head);
	exp = bin_count(max_n(*head));
	while (temp != exp)
	{
		size = lst_size(*head);
		while (size)
		{
			if (((*head)-> number >> temp & 1) == 0)
				push_b(head_b, head);
			else
				rotate_a(head);
			if (!bin_left(*head, temp))
				break ;
			size--;
		}
		while ((*head_b))
			push_a(head, head_b);
		temp++;
	}
}

void	push_swap(int ac, char *arr[])
{
	struct Stacks	*head;
	struct Stacks	*head_b;
	char			**matrix;
	char			*str;
	int				num;

	if (ac < 2)
		exit(0);
	num = 0;
	head = NULL;
	str = NULL;
	while (*++arr)
		str = ft_strjoin(*arr, str);
	matrix = ft_split(str, ' ');
	while (matrix[num])
	{
		if (str_checker (matrix[num])
			|| (head && has_num(head, ft_atoi (matrix[num]))))
			error(head, matrix, str);
		head = lstadd (ft_atoi (matrix[num]), head);
		num++;
	}
	head_b = NULL;
	sort_handler(&head, &head_b);
	return (free_lst(head, matrix, str));
}

int	main(int ac, char *av[])
{
	(void) ac;
	if (ac < 2)
		return (0);
	push_swap(ac, av);
	return (1);
}
