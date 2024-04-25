/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:14:18 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/23 18:28:24 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	len2;

	i = 0;
	len = strlen(src);
	len2 = strlen(dest);
	if (size == 0)
		return (len);
	while (i <= size + 1)
	{
		if (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		else
			break;
	}
	dest[i] = '\0';
	return (i);
} 

/* int	main(void)
{
	char	*dest = "//";
	const char	*src = "a";

	//printf ("Original strlcpy: %ld\n", strlcpy(dest, src, 3));
	printf ("My strlcpy: %ld\n", ft_strlcpy(dest, src, 4));
} */