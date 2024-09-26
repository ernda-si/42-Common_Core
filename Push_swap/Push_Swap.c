/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/26 18:05:55 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Stacks{
	int number;
	struct Stacks *next;
} Stacks;

struct Stacks *head = NULL;
struct Stacks *head_b = NULL;

int lst_size(struct Stacks *head)
{
	struct Stacks *temp;
	int	i;

	temp = head;
	i = 0;
	if (!head)
		return (0);
	while (temp)
	{
		temp = temp -> next;
		i++;
	}
	return (i);
}

int str_checker(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] >= 48 && str[i] <= 57 && str[i])
		str[i++];
	if (!str[i])
		return (1);
	return (0);
}

int	ft_atoi(char const *str)
{
	int		i;
	int		signal;
	long	num;

	i = 0;
	signal = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i++] - '0';
	}
	if (num * signal >= -2147483648 && num * signal <= 2147483647) 
		return (signal * num);
	return (0);
}

struct Stacks *create_node(int new_data)
{
	struct Stacks *new_node = (struct Stacks*)malloc (sizeof(struct Stacks));
	new_node -> number = new_data;
	new_node -> next = NULL;
	return (new_node);
}

struct Stacks *lstadd(int new_data, struct Stacks *start)
{
	struct Stacks *end;
	struct Stacks *node;

	node = create_node(new_data);
	if (!start)
	{
		start = node;
		return (start);
	}
	end = start;
	while (end -> next)
		end = end -> next;
	end -> next = node;
	return (start);
}

void	print_list(struct Stacks *head)
{
	struct Stacks *temp_2;

	temp_2 = head;
	while (temp_2)
	{
		printf("value on nodes: %d\n", temp_2 -> number);
		temp_2 = temp_2 -> next;
	}
}

void print_node(struct Stacks *node)
{
	printf("node value: %d\n", node -> number);
}
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	swap_a(struct Stacks *head)
{
	struct Stacks temp;
	
	if (!head || !head -> next)
		exit(0);
	temp . number = head -> number;
	head -> number = head -> next -> number;
	head -> next -> number = temp . number;
	write(1, "sa\n", 3);
}

// sa (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	swap_b(struct Stacks *head_b)
{
	struct Stacks temp_b;
	
	if (!head_b || !head_b -> next)
		exit(0);
	temp_b . number = head_b -> number;
	head_b -> number = head_b -> next -> number;
	head_b -> next -> number = temp_b . number;
	write(1, "sb\n", 3);
}

// ss : sa and sb at the same time.
void	swap_swap(struct Stacks *head, struct Stacks *head_b)
{
	struct Stacks temp;
	
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

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	push_a(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks *new_node;
	struct Stacks *temp;

	if (!*head_b)
		exit(0);
	new_node = create_node((*head) -> number);
	new_node -> next = (*head )-> next;
	(*head) -> next = new_node;
	(*head) -> number = (*head_b) -> number;
	temp = *head_b;
	*head_b = (*head_b) -> next;
	free(temp);
	write (1, "pa\n", 3);
	// printf("*head_b: %d\n", *head_b->number);
	// printf("temp: %d\n", temp->number);
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(struct Stacks **head_b, struct Stacks **head)
{
	struct Stacks *new_node;
	struct Stacks *temp;

	if (!*head)
		exit(0);
	new_node = create_node((*head_b) -> number);
	new_node -> next = (*head_b) -> next;
	(*head_b) -> next = new_node;
	(*head_b) -> number = (*head) -> number;
	temp = *head;
	*head = (*head) -> next;
	free(temp);
	write (1, "pb\n", 3);
	// printf("*head_b: %d\n", *head_b->number);
	// printf("temp: %d\n", temp->number);
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a(struct Stacks **head)
{
	struct Stacks *end;
	struct Stacks *end_node;
	struct Stacks *temp;

	end_node = create_node((*head) -> number);
	end = *head;
	if (!*head)
		exit(0);
	while (end -> next)
		end = end -> next;
	end -> next = end_node;
	temp = *head;
	*head = (*head) -> next;
	free(temp);
	write (1, "ra\n", 3);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rotate_b(struct Stacks **head_b)
{
	struct Stacks *end;
	struct Stacks *end_node;
	struct Stacks *temp;

	end_node = create_node((*head_b) -> number);
	end = *head_b;
	if (!*head_b)
		exit(0);
	while (end -> next)
		end = end -> next;
	end -> next = end_node;
	temp = *head_b;
	*head_b = (*head_b) -> next;
	free(temp);
	write (1, "rb\n", 3);
}

// rr : ra and rb at the same time.
void	rotate_ab(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks *end;
	struct Stacks *end_node;
	struct Stacks *temp;

	if (!*head_b || !*head)
		exit(0);

	end_node = create_node((*head_b) -> number);
	end = *head_b;
	while (end -> next)
		end = end -> next;
	end -> next = end_node;
	temp = *head_b;
	*head_b = (*head_b) -> next;
	free (temp);

	end_node = create_node((*head) -> number);
	end = *head;
	while (end -> next)
		end = end -> next;
	end -> next = end_node;
	temp = *head;
	*head = (*head) -> next;
	free(temp);

	write (1, "rr\n", 3);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

int	push_swap(int ac, char *arr[])
{
	int	arg;
	int	num;

	arg = 0;
	while (++arg < ac)
	{
		// printf("Reveiced string: %s\n", arr[arg]);
		if (!str_checker(arr[arg]))
			return(0);
		num = ft_atoi(arr[arg]);
		head = lstadd(num, head);
		head_b = lstadd(num, head_b);
		// printf("Converted string: %d\n", num);
	}
	// printf("outside\n");
	// print_node(head);
	// swap_swap(head, head_b);
	printf("Stack A before command:\n");
	print_list(head);
	printf("Stack B before command:\n");
	print_list(head_b);
	// rotate_ab(&head, &head_b);
	// rotate_a(&head);
	// rotate_b(&head_b);
	// push_a(&head, &head_b);
	// push_b(&head_b, &head);
	printf("Stack A after command:\n");
	// swap_a(head);
	print_list(head);
	printf("Stack B after command:\n");
	// swap_b(head_b);
	print_list(head_b);
	return(1);
}

int main(int ac, char *av[])
{
	printf("%d\n", push_swap(ac, av));
	return(1);
}
