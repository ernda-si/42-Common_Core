/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpyUNF.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:14:18 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/13 15:23:16 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, const char *src, size_t size)
{
	while (size > *src)
	{
		*dest = *src;
	}
	
	return(dest);
}

int main(void)
{
	char *dest = "///////";
	const char *src = "abc";
	printf("%s\n", ft_strlcpy(dest, src, 7));
	printf("Original: %s\n", strlcpy(dest, src, 7));
}
