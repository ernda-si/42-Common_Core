/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:51:33 by kali              #+#    #+#             */
/*   Updated: 2024/04/14 14:57:06 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*vs1;
	const char	*vs2;
	size_t	i;

	i = 0;
	vs1 = s1;
	vs2 = s2;
	while (vs1[i] == vs2[i] && i < (n - 1))
		i++;
	return (vs1[i] - vs2[i]);
}

int	main(void)
{
	char *str = "ABakaxi";
	char *str2 = "Abacaxi";

	printf("Original memcmp: %i\n", memcmp(str, str2, 2));
	printf("My memcmp: %i\n", ft_memcmp(str, str2, 2));
}

