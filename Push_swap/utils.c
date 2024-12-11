/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:32:55 by ernda-si          #+#    #+#             */
/*   Updated: 2024/12/11 17:39:02 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		i2;
	char	*s3;

	if (!s2)
		return ((char *)s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	i2 = 0;
	s3 = (char *) malloc (sizeof(char) * (len1 + len2 + 2));
	if (s3 == 0)
		return (NULL);
	while (++i < len1)
		s3[i] = s1[i];
	s3[i++] = ' ';
	while (i2 < len2)
		s3[i++] = s2[i2++];
	s3[i] = '\0';
	return (s3);
}

int	verify(struct Stacks *head)
{
	struct Stacks	*temp;
	struct Stacks	*temp2;

	temp = head;
	temp2 = head -> next;
	while (temp2 -> next && temp -> number < temp2 -> number)
	{
		temp = temp -> next;
		temp2 = temp2 -> next;
	}
	if (temp -> number > temp2 -> number)
		return (0);
	return (1);
}
