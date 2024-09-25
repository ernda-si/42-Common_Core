/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swappp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/25 17:33:22 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

typedef struct Stacks{
	int number;
	struct Stacks *next;
} Stacks;

struct Stacks *head = NULL;

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

/* int	GetMax(int arr[])
{
	int max;
	int i;

	i = 0;
	max = arr[i];
	while (arr[i] && arr[i] > max)
		i++;
	return(max);
}

int	arr_size(int arr[])
{
	int	size;
	
	size = 0;
	while (arr++)
		size++;
	return(size);
} */

struct Stacks *create_node(int new_data)
{
	struct Stacks *new_node = (struct Stacks*)malloc (sizeof(struct Stacks));
	new_node -> number = new_data;
	new_node -> next = NULL;
	return (new_node);
}

struct	Stacks *lstadd(int new_data)
{
	struct Stacks *end;
	struct Stacks *node;

	node = create_node(new_data);
	if (!head)
		return (head = node);
	end = head;
	while (end)
		end = end -> next;
	node = end;
	return (node);
}

void	print_list()
{
	struct Stacks *h;

	while (h)
	{
		printf("value on node: %d\n", h -> number);
		h = h -> next;
	}
}

void print_node(struct Stacks *node)
{
	printf("node value: %d\n", node -> number);
}

int	push_swap(int ac, char *arr[])
{
	int	arg;
	int	num;

	arg = 0;
	while (++arg < ac)
	{
		printf("Reveiced string: %s\n", arr[arg]);
		if (!str_checker(arr[arg]))
			return(0);
		num = ft_atoi(arr[arg]);
		lstadd(num);
		printf("Converted string: %d\n", num);
	}
	printf("outside\n");
	print_node(head);
	return(1);
}

int main(int ac, char *av[])
{
	printf("%d\n", push_swap(ac, av));
	return(1);
}
