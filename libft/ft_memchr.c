/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:20:51 by kali              #+#    #+#             */
/*   Updated: 2025/07/14 13:22:16 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*vstr;
	size_t		i;

	vstr = str;
	i = 0;
	while (i < n)
	{
		if (vstr[i] == (unsigned char)c || vstr[i] == c)
			return ((void *)&vstr[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	*str = "Abacaxi";
	int		tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf ("Original memchr: %s\n", (char *)memchr(str, -1, 5));
	printf ("My memchr: %s\n", (char *)ft_memchr(str, -1, 5));

	printf("Original memchr2: %s\n", (char *)memchr(tab, -1, 7));
	printf("My memchr2: %s\n", (char *)ft_memchr(tab, -1, 7));
} */