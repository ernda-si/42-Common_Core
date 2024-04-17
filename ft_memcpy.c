/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpyUNF.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:42:39 by kali              #+#    #+#             */
/*   Updated: 2024/04/17 14:24:15 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, void *src, size_t n)
{
	char *vdest;
	char *vsrc;
	size_t i;

	vdest = dest;
	vsrc = src;
	i = 0;
	while (i < n)
	{
		i++;
		vdest[i] = vsrc[i];
	}
	return (vsrc);
}

/* int	main(int ac, char **av)
{
	(void) ac;
	printf("Original memcpy: %s\n", memcpy(av[1], av[2], 3));
	printf("My memcpy: %s", ft_memcpy (av[1], av[2], 3));
} */

