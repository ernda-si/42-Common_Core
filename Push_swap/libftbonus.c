/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftbonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:16:08 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/25 11:51:49 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list{
	void *content;
	struct s_list *next;
} t_list;

void ft_printlist()
{
	struct	s_list *temp;
	
	while (temp)
	{
		printf("%s\n", temp->content);
		temp = temp->next;
	}
}

void *ft_lstnew(void *content)
{
	t_list *lastnode = (t_list *) malloc(sizeof(t_list));
	lastnode->content = content;
	lastnode->next = NULL;
	return lastnode;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	
}

int	main(void)
{
	ft_lstnew("42");
	ft_printlist();
}