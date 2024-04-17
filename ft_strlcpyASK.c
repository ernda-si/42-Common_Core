/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:14:18 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/17 17:57:21 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	while (src[len] != '\0')
		len++;
	if (src[i] == '\0')
		return (len);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return(len);
} 

int	main(void)
{
	char	*dest = "//";
	const char	*src = "abc";

	//printf ("Original strlcpy: %ld\n", strlcpy(dest, src, 3));
	printf ("My strlcpy: %ld\n", ft_strlcpy(dest, src, 3));
}
