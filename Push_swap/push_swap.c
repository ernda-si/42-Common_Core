/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/10/01 17:51:21 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_num(struct Stacks *head)
{
	struct Stacks	*big_num;
	struct Stacks	*temp;
	int				num;

	big_num = head;
	temp = create_node(head->number);
	temp->next = head->next;

	while (big_num)
	{
		if ((temp -> number) < (big_num -> number) && big_num)
			temp -> number = big_num -> number;
		big_num = big_num -> next;
	}
	num = temp->number;
	free(temp);
	return (num);
}

int	bin_max(int max_num)
{
	int	bits;

	bits = 0;
	while (max_num)
	{
		printf("max_num: %d\n", max_num);
		bits++;
		max_num >>= 1;
	}
	printf("bits:%d\n", bits);
	return(bits);
}

int	bit_sets(int max_num)
{
	int	bits;

	bits = 0;
	while (max_num)
	{
		bits += max_num & 1;
		max_num >>= 1;
	}
	return(bits);
}

void	radix_sort(struct Stacks **head, struct Stacks **head_b)
{
	// struct Stacks *current;
	int	exp;
	int	i;
	int	max_num;
	// current = *head;
	max_num = find_max_num(*head)
	i = -1;
	exp = bin_max(max_num);
	printf("exp: %d\n", exp);
	while (++i < exp && *head)
	{
		push_b(head_b, head);
		// printf("teste %d\n", exp);
		rotate_a(head);
		// current = current -> next;
	}

	printf("\nhead: %d\n", (*head)-> number);
	if ((*head_b))
		printf("\nhead_b: %d\n", (*head_b)-> number);
	print_list(*head);
	print_list(*head_b);
}

int	push_swap(int ac, char *arr[])
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
			return (0);
		num = ft_atoi (arr[arg]);
		head = lstadd (num, head);
	}
	radix_sort(&head, &head_b);
	free(head);
	free(head_b);
	return (1);
}

int	main(int ac, char *av[])
{
	printf ("%d\n", push_swap(ac, av));
	return(1);
}
	// printf("Stack B before command:\n");
	// print_list(head_b);
	// printf("Stack A after command:\n");
	// print_list(head);
	// printf("Stack B after command:\n");
	// print_list(head_b);

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

