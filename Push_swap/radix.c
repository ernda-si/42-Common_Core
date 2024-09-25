/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:12:06 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/23 15:43:33 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	*radix_sorting(int *lista)
{
	int	i;
	
	i = 0;

	return(lista);
}
struct staks *head = NULL;
struct node *current = NULL;

void PrintList()
{
	struct node *h = head;
	while (h != NULL)
	{
		printf("%d\n", h -> data);
		h = h -> next;
	}
}

int	main()
{
	int	lista[] = {1,2,3,4,5};
	int	*sorted_list = radix_sorting(lista);
	int	i = 0;

	while (i < 5)
		printf("%d\n", sorted_list[i++]);
}