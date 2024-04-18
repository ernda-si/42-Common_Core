/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:51:33 by kali              #+#    #+#             */
/*   Updated: 2024/04/18 15:44:14 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*vs1;
	const unsigned char	*vs2;
	size_t		i;

	i = 0;
	vs1 = s1;
	vs2 = s2;
	while (n--)
	{
		if (vs1[i] < vs2[i] || vs1[i] > vs2[i])
			return (vs1[i] - vs2[i]);
		if (vs1[i] == vs2[i] && !n)
			return (0);
		i++;
	}
	return (0);
}
int	main(void)
{
	char *str = "ABakaxi";
	char *str2 = "Abacaxi";

	printf("Original memcmp: %i\n", memcmp(str, str2, 2));
	printf("My memcmp: %i\n", ft_memcmp(str, str2, 2));

	printf("Original memcmp2: %i\n", memcmp("t\200", "t\0", 2));
	printf("My memcmp2: %i\n", ft_memcmp("t\200", "t\0", 2));

	printf("Original memcmp3: %i\n", memcmp("zyxbcdefgh", "abcdefgxyz", 0));
	printf("My memcmp3: %i\n", ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
}