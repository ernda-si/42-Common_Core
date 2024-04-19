/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:23:29 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/19 11:52:38 by ernda-si         ###   ########.fr       */
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
/* int	main(int ac, char **av)
{
	(void) ac;

	printf ("Original strlcat: %ld\n", strlcat(av[1], av[2], 2));
	printf ("My strlcat: %ld\n", ft_strlcat(av[1], av[2], 2));
} */