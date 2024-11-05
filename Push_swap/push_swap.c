/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/11/05 17:54:30 by ernda-si         ###   ########.fr       */
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
	// printf("size: %d\n", size);
	return (size);
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

void	rmedium_sort(struct Stacks **head)
{
	int	first;
	int	second;
	int	third;
	
	first = (*head)-> number;
	second = (*head)-> next -> number;
	third = (*head)-> next -> next -> number;
	// 1 < 2  < 3 null
	if (first > second && second > third)
		return ;
	// 1 < 3 > 2 sa ra
	else if (first > second && second < third && third < first)
		return (swap_a(*head), rotate_a(head));
	// 2 > 1 < 3 sa
	else if(first < second && second > third && third < first)
		return (swap_a(*head));
	// 2 < 3 > 1 rra
	else if(first > second && second < third && third > first)
		return (rrotate_a(head));
	// 3 > 2 > 1 rra rra
	else if(first < second && second < third)
		return (rotate_a(head), swap_a(*head));
	// 3 > 1 < 2 ra
	else if(first < second && second > third)
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

int	better_moves(struct Stacks *head, struct Stacks *head_b)
{
	int	size;
	int	mid;
	int	counter;
	struct Stacks *temp;

	size = lst_size(head);
	mid = size / 2;
	counter = 0;
	temp = head;
	while (temp -> number > head_b -> number && last_node(temp) < head_b -> number)
	{
		temp = temp -> next;
		counter++;
		printf("count ");
	}
	if (counter < mid && counter < size)
		return (counter);
	else if (counter > mid && counter < size)
		return (counter);
	return(counter);
}

void	big_sort(struct Stacks **head, struct Stacks **head_b)
{
	int	last;
	printf("min number: %d\n", find_min_num(*head));
	// while ((*head)-> number != find_min_num(*head))
	// 	rotate_a(head);
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

int	find_max(struct Stacks **head)
{
	struct Stacks *temp;
	int	max;
	int	i;

	i = 0;
	temp = *head;
	max = find_max_num(*head);
	while (temp -> number != max && temp)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}

int find_min(struct Stacks **head)
{
	struct Stacks *temp;
	int	min;
	int	i;

	i = 0;
	temp = *head;
	min = find_min_num(*head);
	while (temp -> number != min && temp)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}
// 1 3 2 -2 7 6 4 -1 // -2 7 6 4 -1 | 2 3 1
// max_num na head // (rotate _b if max_num_B < mid) ou (rrotate_b if max_num_B > mid)
// min_num na head // (rotate _b if min_num_B < mid) ou (rrotate_b if min_num_B > mid)
// (push_b swap_b if min ou max da head for == min ou max da head_b)
void handler(struct Stacks **head, struct Stacks **head_b)
{
	int	moves;
	int	mid;
	int	find_mx;
	int	find_mn;

	mid = lst_size(*head_b);
	find_mx = find_max(head_b);
	find_mn = find_min(head_b);
	printf("find_mx: %d\n", find_mx);
	printf("find_mn: %d\n", find_mn);
	printf("Ehandler\n");
	if ((*head)-> number == find_max_num(*head) || (*head)-> number == find_min_num(*head) 
	&& find_mx <= mid || find_mn < mid)
	{
		printf("A\n");
		if (find_min_num(*head) == (*head)-> number && find_min_num(*head_b) == (*head_b)-> number)
			return(push_b(head_b, head));
		else if (find_max_num(*head) == (*head)-> number && find_max_num(*head_b) == (*head_b)-> number)
		{
			push_b(head_b, head);
			swap_b(*head_b);
		}
		return(rotate_b(head_b));
	}
	else if ((*head) -> number == find_max_num(*head) || (*head) -> number == find_min_num(*head) 
	&& find_mx >= mid || find_mn > mid)
	{
		printf("B\n");
		if (find_min_num(*head) == (*head)-> number && find_min_num(*head_b) == (*head_b)-> number)
		{
			push_b(head_b, head);
			swap_b(*head_b);
		}
		else if (find_max_num(*head) == (*head)-> number && find_max_num(*head_b) == (*head_b)-> number)
			return(push_b(head_b, head));
		return(rrotate_b(head_b));
	}
	moves = better_moves(*head, *head_b);
	if (moves < mid && moves)
	{
		printf("C\n");
		return (rotate_b(head_b));
	}
	else if (moves > mid && moves < lst_size(*head_b))
	{
		printf("D\n");
		return (rrotate_b(head_b));
	}
	printf("handler\n");
}

// 2 6 4 -1 1 3 | 7 -2 // 6 4 -1 1 3 | 2 7 -2 // 4 -1 1 3 | 6 7 -2 2 // -1 1 3 | 4 6 7 -2 2 //
// 1 3 | 2 4 6 7 -2 -1 // 3 | 1 2 4 6 7 -2 -1 // 1 2 3 4 6 7 -2 -1 // -1 1 2 3 4 6 7 -2 //
// -2 -1 1 2 3 4 6 7
// if (fA > fB && fA > lB) (rotate_b if < mid && existir) ou (rrotate_b if > mid && < size)
// if (fA < fB && fA < lB) (rotate_b if < mid && existir) ou (rrotate_b if > mid && < size)
// if (fA < fB && fA > lB) push_b
// if (fA > fB && fA < lB) (rotate_b if < mid && existir) ou (rrotate_b if > mid && < size)

void	sort(struct Stacks **head, struct Stacks **head_b)
{
	int	fA;
	int	fB;
	int	lB;
	int	i = 0;

	push_b(head_b, head);
	push_b(head_b, head);
	rsmall_sort(head_b);
	while (head)
	{
		fA = (*head)-> number;
		fB = (*head_b)-> number;
		lB = last_node(*head_b);
		printf("fA: %d\n", fA);
		printf("fB: %d\n", fB);
		printf("lB: %d\n", lB);
		if (fA < fB && fA > lB)
			push_b(head_b, head);
		else if (fA < fB && fA < lB || fA > fB && fA > lB || fA > fB && fA < lB)
			handler(head, head_b);
		i++;
		if (i == 13)
			break;
	}
	// while ((*head_b))
	// 	push_a(head, head_b);
} // 1 3 2 7 4 6 5 // 

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

void	free_lst(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks	*temp;
	int				size;
	int				size_b;

	size = lst_size(*head);
	size_b = lst_size(*head_b);
	if ((*head))
	{
		while (--size)
		{
			temp = (*head);
			while (temp)
				temp = temp -> next;
			free(temp);
		}
	}
}

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
	int				arg;
	int				num;

	arg = 0;
	while (++arg < ac)
	{
		if (!str_checker (arr[arg]))
		{
			free_lst(&head, &head_b);
			exit(1);
		}
		num = ft_atoi (arr[arg]);
		if ((head && has_num(head, num)))
		{
			write(2, "Error\n", 6);
			free_lst(&head, &head_b);
			exit(1);
		}
		head = lstadd (num, head);
	}
	head_b = (struct Stacks *) malloc (sizeof(struct Stacks));
	if (!head_b)
		return ;
	head_b = NULL;

	printf("Stack A before sorting:\n");
	print_list(head);
	printf("Stack B before sorting:\n");
	print_list(head_b);

	sort_handler(&head, &head_b);

	printf("Stack A after sorting:\n");
	print_list(head);
	printf("Stack B after sorting:\n");
	print_list(head_b);

	free_lst(&head, &head_b);
	return ;
}

int	main(int ac, char *av[])
{
	push_swap(ac, av);
	return (1);
}
