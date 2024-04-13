/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:26:37 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/13 15:11:07 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *ptr, int x, size_t n)
{
	char *vptr = ptr;

	while (n--)
	{
		*vptr++ = x;
	}
	if (*vptr == '\0')
		return ("NULL");
	return(ptr);
}

int	main(void)
{
	/*int	test = 42; ask about it!!!*/
	char ptr[] = "abcdef";
	printf("Original memset: %s\n", memset(ptr, 42, 3));
	printf("My memset: %s\n", ft_memset(ptr, 42, 3));
}