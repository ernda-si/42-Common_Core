/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmoveUNF.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:25:30 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/15 11:39:29 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*vdest = dest;
	const char *vsrc = src;

	while (dest <= src || dest > src && (n--) && *vdest != '\0' && *vsrc != '\0')
	{
		*vdest++ = *vsrc++;
	}
	if (*vdest == '\0' && *vsrc == '\0')
		return ("NULL");
	return (dest);
}

/* int main(void)
{
	char dest[] = "abcdef";
	char src[] = "123";

	printf("My memmove: %s\n", ft_memmove(dest, src, sizeof(char) * 2));
	printf("Original memmove: %s\n", memmove(dest, src, sizeof(char) * 2));
} */