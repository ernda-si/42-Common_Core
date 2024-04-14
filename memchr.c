/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:20:51 by kali              #+#    #+#             */
/*   Updated: 2024/04/14 16:34:02 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*vstr;
	size_t	i;

	vstr = str;
	i = 0;
	while (i < n)
	{
		if (vstr[i] == c)
			return ((void *)&vstr[i]);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	test = 'a';
	char	*str = "Abacaxi";

	printf("%i\n", test);
	printf ("Original memchr:%s\n", memchr(str, 'a', 5));
	printf ("My memchr:%s\n", ft_memchr(str, 'a', 5));
}

