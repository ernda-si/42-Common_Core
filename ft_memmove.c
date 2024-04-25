/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:38:24 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/25 13:38:36 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*vsrc;
	char	*vdest;
	size_t	i;
	size_t	srclen;

	vsrc = (char *) src;
	vdest = (char *) dest;
	srclen = 0;
	i = 0;
	while (dest <= src && i < n)
	{
		vdest[i] = vsrc[i];
		i++;
	}
	while (dest > src && n--)
		vdest[n] = vsrc[n];
	return (vdest);
}

/* int main(void)
{
	char dest[] = "abcdef";
	char src[] = "123";

	printf("My memmove: %s\n", (char * )ft_memmove(dest, src, sizeof(char) * 2));
	printf("Original memmove: %s\n", (char *)memmove(dest, src, sizeof(char) * 2));
} */