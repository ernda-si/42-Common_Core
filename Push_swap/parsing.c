/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:27:24 by kali              #+#    #+#             */
/*   Updated: 2024/12/12 19:42:06 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_parse(int ac, char *arr[])
{
	struct Stacks	*head;
	struct Stacks	*head_b;
	char			**matrix;
	int				num;

	if (ac < 2 || !arr[1][0] || !check_num(arr[1]))
		return ((void)write(1, "Error\n", 6));
	num = 0;
	head = NULL;
	matrix = ft_split(arr[1], ' ');
	while (matrix[num])
	{
		if (str_checker (matrix[num])
			|| (head && has_num(head, ft_atoi (matrix[num]))))
			return(error_all(head, matrix));
		head = lstadd (ft_atoi (matrix[num]), head);
		num++;
	}
	head_b = NULL;
	sort_handler(&head, &head_b);
	return (free_all(head, matrix));
}

void	args_parse(int ac, char *arr[])
{
	struct Stacks	*head;
	struct Stacks	*head_b;
	int				arg;

	if (ac < 2 || !check_num(arr[1]))
		return ((void)write(1, "Error\n", 6));
	arg = 1;
	head = NULL;
	while (arr[arg])
	{
		if (str_checker (arr[arg])
			|| (head && has_num(head, ft_atoi (arr[arg]))))
			return(error(head));
		head = lstadd (ft_atoi (arr[arg]), head);
		arg++;
	}
	head_b = NULL;
	sort_handler(&head, &head_b);
	return (free_lst(head));
}

void    error(struct Stacks *head)
{
    if (head)
		free_lst (head);
	exit(1);
}

void    free_lst(struct Stacks *head)
{
    struct Stacks *temp;

    while (head)
	{
		temp = head;
		head = head -> next;
		free(temp);
	}
}