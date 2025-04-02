/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:25:26 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/02 12:51:20 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_bin(unsigned int num)
{
	if (num > 1)
		printf_bin(num / 2);
	write (1, &"0123456789"[num % 2], 1);
}

int	bin_left(t_stacks *head, int exp)
{
	t_stacks	*temp;

	temp = head;
	while (temp)
	{
		if ((temp -> index << exp & 1) == 0)
			return (1);
		temp = temp -> next;
	}
	return (0);
}

int	bin_count(int num)
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

int	ft_strlen(const char *str)
{
	if (!*str)
		return (0);
	return (ft_strlen ((str + 1)) + 1);
}

void	sort_handler(t_stacks **head, t_stacks **head_b)
{
	int	size;

	size = lst_size(*head);
	if (lst_size(*head) == 1 || verify(*head))
		return ;
	if (size == 1)
		return ;
	else if (size == 2)
		return (small_sort(head));
	else if (size == 3)
		return (medium_sort(head));
	else if (size == 5 || size == 4)
		return (big_sort(head, head_b));
	else if (size > 5)
		return (sort(head, head_b));
	return ;
}
