/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:23:29 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/26 11:44:08 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;
	size_t	len;
	size_t	left;

	i = 0;
	i2 = 0;
	len = 0;
	while (src[len])
		len++;
	while (dst[i] != '\0' && i < size)
		i++;
	left = size - i;
	if (left == 0)
		return (i + len);
	while (src[i2] != '\0' && i + i2 < (size - 1))
	{
		dst[i + i2] = src[i2];
		i2++;
	}
	dst[i + i2] = '\0';
	return (i + len);
}
// 5 6 7 8 issue //
/* int	main(void)
{
	char *dst = "abcd";
	char *src = "123";

	printf ("Original strlcat: %ld\n", strlcat(dst, src, 1));
	printf ("My strlcat: %ld\n", ft_strlcat(dst, src, 1));
} */