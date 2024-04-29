/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:31:56 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/29 14:12:15 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!(new))
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
/* int	main(void)
{
	int	i = 1;
	printf("%d", ft_lstnew((void *)i));
} */