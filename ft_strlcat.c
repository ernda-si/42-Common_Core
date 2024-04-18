/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:23:29 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/18 15:37:09 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[i2] != '\0')
		i2++;
	return (i + i2);
}
// 1 3 4 issue //
/* int	main(void)
{
	printf ("Original strlcat: %ld\n", strlcat("愛", "a", sizeof(char) * 3));
	printf ("My strlcat: %ld\n", ft_strlcat("愛", "a", sizeof(char) * 3));
} */
