/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/27 18:49:50 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct Stacks *find_big_num(struct Stacks *head)
{
	struct Stacks	*big_num;
	struct Stacks	*temp;

	big_num = head;
	temp = big_num;
	while (big_num)
	{
		if ((temp -> number) < (big_num -> number) && big_num)
			temp -> number = big_num -> number;
		big_num = big_num -> next;
		printf("big_num_process: %d\n", temp -> number);
	}
	return (temp);
}

void	radix_sort(struct Stacks **head)
{
	struct Stacks *big_num;

	big_num = find_big_num(*head);
	printf("big_num_final: %d\n", big_num -> number);
	printf("head: %d\n", (*head)-> number);
	print_list(*head);
}

int	push_swap(int ac, char *arr[])
{
	struct Stacks	*head;
	struct Stacks	*head_b;
	int				arg;
	int				num;

	head = NULL;
	head_b = NULL;
	arg = 0;
	while (++arg < ac)
	{
		if (!str_checker (arr[arg]))
			return (0);
		num = ft_atoi (arr[arg]);
		head = lstadd (num, head);
		head_b = lstadd (num, head_b);
	}
	radix_sort(&head);
	// printf("Stack A before command:\n");
	// print_list(head);
	// printf("Stack B before command:\n");
	// print_list(head_b);
	// printf("Stack A after command:\n");
	// print_list(head);
	// printf("Stack B after command:\n");
	// print_list(head_b);
	return (1);
}
	// print_node(head);
	// printf("Stack A before command:\n");
	// print_list(head);
	// printf("Stack B before command:\n");
	// print_list(head_b);
	// printf("Stack A after command:\n");
	// print_list(head);
	// printf("Stack B after command:\n");
	// print_list(head_b);
	// rrotate_a(&head);
	// rrotate_b(&head_b);
	// rrotate_ab(&head, &head_b);
	// rotate_ab(&head, &head_b);
	// rotate_a(&head);
	// rotate_b(&head_b);
	// push_a(&head, &head_b);
	// push_b(&head_b, &head);
	// swap_a(head);
	// swap_b(head_b);
	// swap_swap(head, head_b);

int	main(int ac, char *av[])
{
	printf ("%d\n", push_swap(ac, av));
	return(1);
}
