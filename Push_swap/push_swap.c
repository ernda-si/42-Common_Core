/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/12/03 17:54:52 by ernda-si         ###   ########.fr       */
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

void	min_max(struct Stacks **head, struct Stacks **head_b)
{
	int	max_num;
	int	min_num;

	max_num = max_n(*head);
	min_num = min_n(*head);
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

void	small_sort(struct Stacks **head)
{
	if ((*head)-> number > (*head)-> next -> number)
		swap_a(*head);
	else
		return ;
}

void	rsmall_sort(struct Stacks **head)
{
	if ((*head)-> number < (*head)-> next -> number)
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
	// 1 < 2  < 3 null
	if (first < second && second < third)
		return ;
	// 1 < 3 > 2 sa ra
	else if (first < second && second > third && third > first)
		return (swap_a(*head), rotate_a(head));
	// 2 > 1 < 3 sa
	else if(first > second && second < third && third > first)
		return (swap_a(*head));
	// 2 < 3 > 1 rra
	else if(first < second && second > third && third < first)
		return (rrotate_a(head));
	// 3 > 2 > 1 rra rra
	else if(first > second && second > third)
		return (rotate_a(head), swap_a(*head));
	// 3 > 1 < 2 ra
	else if(first > second && second < third)
		return (rotate_a(head));
}

int	last_node(struct Stacks *head)
{
	int	size;
	struct Stacks *temp;

	size = lst_size(head);
	temp = head;
	while (--size)
		temp = temp -> next;
	return (temp -> number);
}

void	big_sort(struct Stacks **head, struct Stacks **head_b)
{
	int	last;
	// printf("min number: %d\n", min_n(*head));
	while ((*head)-> number != min_n(*head))
		rotate_a(head);
	push_b(head_b, head);
	push_b(head_b, head);
	small_sort(head_b);
	medium_sort(head);
	while (*head_b)
	{ // 1 3 5 4 2 > 1 3 | 2 4 5 > 
		last = last_node(*head);
		if ((*head_b)-> number > last && (*head_b)-> number < (*head)-> number)
		{
			rotate_a(head);
			push_a(head, head_b);
		}
		else if ((*head_b)-> number < last && (*head_b)-> number > (*head)-> number)
			rotate_a(head);
		else
			rotate_a(head);
	}
	return ;
}

struct Stacks	*find_max(struct Stacks **head)
{
	struct Stacks *temp;
	int	max;

	temp = *head;
	max = max_n(*head);
	while (temp -> number != max && temp && temp)
	{
		temp = temp -> next;
	}
	return (temp);
}

int find_min(struct Stacks **head)
{
	struct Stacks *temp;
	int	min;
	int	i;

	i = 0;
	temp = *head;
	min = min_n(*head);
	while (temp -> number != min && temp)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}

int	has_bigger(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks *temp;
	
	temp = *head;
	while (temp -> number < (*head_b)-> number)
	{
		temp = temp -> next;
		if (temp -> next == NULL)
			return (0);
	}
	return (1);
}

int	has_smaller(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks *temp;
	
	temp = *head;
	while (temp -> number > (*head_b)-> number)
	{
		temp = temp -> next;
		if (temp -> next == NULL)
			return (0);
	}
	return (1);
}

void end_sort(struct Stacks **head)
{
	while (find_min(head) > lst_size(*head) / 2)
		rrotate_a(head);
	while (find_min(head) < lst_size(*head) / 2 && min_n(*head) != (*head)-> number)
		rotate_a(head);
	if (last_node(*head) != max_n(*head))
		return (rrotate_a(head), swap_a(*head));
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


void	free_lst(struct Stacks **head)
{
	struct Stacks	*temp;
	int				size;

	size = lst_size (*head);
	if ((*head))
	{
		while (--size)
		{
			temp = (*head);
			while (temp)
				temp = temp -> next;
			free (temp);
		}
	}
}

int bin_count(int num)
{
    int	counter;

	counter = 0;
	while (num)
	{
		counter ++;
		num = num >> 1;
	}
	return (counter);
}


void     printf_bin(unsigned int num)
{
        if (num > 1)
                printf_bin(num / 2);
        write(1, &"0123456789"[num % 2], 1);
}

void	index_num(struct Stacks **head)
{
	struct Stacks *node;
	int	min;

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

int	bin_left(struct Stacks *head, int exp)
{
	struct Stacks *temp;

	temp = head;
	while (temp)
	{
		// printf("temp on function: %d\n", temp -> number);
		if ((temp -> number << exp & 1) == 0)
			return(1);
		temp = temp -> next;
	}
	return (0);
}

void	sort(struct Stacks **head, struct Stacks **head_b)
{
	int	exp;
	int	temp;
	int	size;

	temp = 0;
	if (min_n(*head) < 0)
		index_num(head);
	// printf_bin(max_n(*head));
	// printf(" max: %d\n", max_n(*head));
	exp = bin_count(max_n(*head));
	// printf ("exp: %d\n", exp);
	while (temp != exp)
	{
		size = lst_size(*head);
		while (size)
		{
			// printf_bin((*head)-> number);
			// printf(" is the bit set of number: %d\n", (*head) -> number);
			if (((*head) -> number >> temp & 1) == 0)
				push_b(head_b, head);
			else
				rotate_a(head);
			if (!bin_left(*head, temp))
				break;
			size--;
		}
		while ((*head_b))
			push_a(head, head_b);
		temp++;
	}
}												// 2 1 9 8 10 5 3

void sort_handler(struct Stacks **head, struct Stacks **head_b)
{
	int	size;

	size = lst_size(*head);
	if (size == 1)
		return ;
	else if (size == 2)
		return (small_sort(head));
	else if (size == 3)
		return (medium_sort(head));
	else if (size == 5)
		return (big_sort(head, head_b));
	else if (size > 5)
		return (sort(head, head_b));
	return ;
}

int	ft_strlen(const char *str)
{
	if (!*str)
		return 0;
	return ft_strlen((str + 1)) + 1;
}

void	push_swap(int ac, char *arr[])
{
	struct Stacks	*head;
	struct Stacks	*head_b;
	char			**matrix;
	int				arg;
	int				num;

	if (ac > 2)
		exit(0);
	arg = 0;
	matrix = ft_split(arr[1], ' ');
	// printf("matrix: %s\n", *matrix);
	while (matrix[arg])
	{
		if (!str_checker (matrix[arg]))
		{
			free_lst(&head);
			exit(1);
		}
		num = ft_atoi (matrix[arg]);
		if ((head && has_num(head, num)))
		{
			write(2, "Error\n", 6);
			free_lst(&head);
			exit(1);
		}
		head = lstadd (num, head);
		arg++;
	}
	head_b = (struct Stacks *) malloc (sizeof(struct Stacks));
	if (!head_b)
		return ;
	head_b = NULL;

	// printf("Stack A before sorting:\n");
	// print_list(head);
	// printf("Stack B before sorting:\n");
	// print_list(head_b);

	sort_handler(&head, &head_b);

	// printf("Stack A after sorting:\n");
	// print_list(head);
	// printf("Stack B after sorting:\n");
	// print_list(head_b);

	free_lst(&head);
	return ;
}

int	main(int ac, char *av[])
{
	(void) ac;
	if (ac < 2)
		return(0);
	push_swap(ac, av);
	return (1);
}
