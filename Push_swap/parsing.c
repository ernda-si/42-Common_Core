/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:27:24 by kali              #+#    #+#             */
/*   Updated: 2025/01/07 18:06:55 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_parse(int ac, char *arr[])
{
	t_stacks	*head;
	t_stacks	*head_b;
	char		**matrix;
	int			num;

	if (ac < 2 || !arr[1][0] || !check_num(arr[1]))
		return ((void)write(2, "Error\n", 6));
	num = 0;
	head = NULL;
	matrix = ft_split(arr[1], ' ');
	while (matrix[num])
	{
		if (!num_valid (matrix[num])
			|| str_checker (matrix[num])
			|| (head && has_num(head, ft_atoi (matrix[num]))))
			return (error_all(head, matrix));
		head = lstadd (ft_atoi (matrix[num]), head);
		num++;
	}
	head_b = NULL;
	sort_handler(&head, &head_b);
	return (free_all(head, matrix));
}

void	args_parse(int ac, char *arr[])
{
	t_stacks	*head;
	t_stacks	*head_b;
	int			arg;

	if (ac < 2 || !check_num(arr[1]))
		return ((void)write(2, "Error\n", 6));
	arg = 1;
	head = NULL;
	while (arr[arg])
	{
		if (!num_valid (arr[arg])
			|| str_checker (arr[arg])
			|| (head && has_num(head, ft_atoi (arr[arg]))))
			return (error(head));
		head = lstadd (ft_atoi (arr[arg]), head);
		arg++;
	}
	head_b = NULL;
	sort_handler(&head, &head_b);
	return (free_lst(head));
}

void	error(t_stacks *head)
{
	if (head)
		free_lst (head);
	write (2, "Error\n", 6);
	exit (1);
}

void	free_lst(t_stacks *head)
{
	t_stacks	*temp;

	while (head)
	{
		temp = head;
		head = head -> next;
		free (temp);
	}
}
