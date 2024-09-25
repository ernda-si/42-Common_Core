/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:22:59 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/23 16:04:34 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

struct stacks{
	int data;
	struct stacks *next;
};

struct stacks *head = NULL;
struct stacks *current = NULL;

void InsertAtEnd(int content)
{
	struct stacks *link = (struct stacks*)malloc (sizeof(struct stacks));
	
}

void sa()
{
	
	int temp;
	temp = head->data;

	write(1, "sa\n", 3);
}

void PrintList()
{
	struct stacks *h = head;
	while (h != NULL)
	{
		printf("%d\n", h -> data);
		h = h -> next;
	}
}

int	main()
{
	InsertAtEnd(1);
	InsertAtEnd(2);
	InsertAtEnd(3);
	// sa();
	PrintList();
}