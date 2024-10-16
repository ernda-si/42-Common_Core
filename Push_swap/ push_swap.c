/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    push_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/10/16 14:51:12 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_num(struct Stacks *head)
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
	// printf("max_number: %d\n", max)
	return (max);
}

int	find_min_num(struct Stacks *head)
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
	// printf("min_number: %d\n", min);
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
	printf("size: %d\n", size);
	return (size);
}

void	small_sort(struct Stacks **head)
{
	if ((*head)-> number > (*head)-> next -> number)
		swap_a(*head);
	else
		return ;
}

void	min_max(struct Stacks **head, struct Stacks **head_b)
{
	int	max_num;
	int	min_num;

	max_num = find_max_num(*head);
	min_num = find_min_num(*head);
	while ((*head))
	{
		rotate_a(head);
		if ((*head)-> number == max_num)
		{
			push_b(head_b, head);
			break ;
		}
	}
	while ((*head))
	{
		rotate_a(head);
		if ((*head)-> number == min_num)
		{
			push_b(head_b, head);
			break ;
		}
	}
}

void	sort(struct Stacks **head, struct Stacks **head_b)
{
	int	count;

	count = 1;
	min_max(head, head_b);
	while ((*head))
	{
		while ((*head)-> number < (*head_b)-> number)
		{
			count++;
			rotate_b(head_b);
		}
		if ((*head)-> number > (*head_b)-> number)
			push_b(head_b, head);
		while (count)
		{
			count--;
			rrotate_b(head_b);
		}
	}
	while ((*head_b))
		push_a(head, head_b);
}

int	has_num(struct Stacks *head, int num)
{
	struct Stacks	*check;

	check = head;
	while (check -> next)
	{
		if (check -> number == num)
			return (1);
		check = check -> next;
	}
	return (0);
}

void	free_lst(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks *temp;

	if ((*head))
	{
		while ((*head))
		{
			temp = (*head);
			while (temp && temp -> next)
				temp = temp -> next;
			free(temp);
		}
	}
	if ((*head_b))
	{
		while ((*head_b))
		{
			temp = (*head_b);
			while (temp && temp -> next)
				temp = temp -> next;
			free(temp);
		}	
	}
}

void	push_swap(int ac, char *arr[])
{
	struct Stacks	*head;
	struct Stacks	*head_b;
	int				arg;
	int				num;

	head_b = (struct Stacks *) malloc (sizeof(struct Stacks));
	head_b = NULL;
	arg = 0;
	while (++arg < ac)
	{
		if (!str_checker (arr[arg]))
			exit(1);
		num = ft_atoi (arr[arg]);
		if (head && has_num(head, num))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		head = lstadd (num, head);
	}
	printf("Stack A before sorting:\n");
	print_list(head);
	printf("Stack B before sorting:\n");
	print_list(head_b);
	sort(&head, &head_b);
	printf("Stack A after sorting:\n");
	print_list(head);
	printf("Stack B after sorting:\n");
	print_list(head_b);
	// free_lst(&head, &head_b);
	free(head);
	free(head_b);
}

int	main(int ac, char *av[])
{
	push_swap(ac, av);
	return (1);
}
