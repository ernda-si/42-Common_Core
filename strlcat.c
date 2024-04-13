/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:23:29 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/13 19:49:09 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (dst[i] != '\0' && size > i)
		i++;
	while (src[i2] != '\0')
		i2++;
	return (i + i2);
}

int	main(void)
{
	printf("Original strlcat: %ld\n", strlcat("Abacaxi", "Uva", sizeof(char) * 3));
	printf("My strlcat: %ld\n", ft_strlcat("Abacaxi", "Uva", sizeof (char) * 3));
}