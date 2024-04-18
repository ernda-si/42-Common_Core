/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:01:11 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/18 13:23:43 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	s = malloc (nmemb * size);
	if (s == 0)
		return (0);
	bzero (s, nmemb * size);
	return (s);
}

/*int	main(void)
{
	printf("Original calloc: %d\n", calloc(1, 1000));
	printf("My calloc: %d\n", ft_calloc(1, 1000));
}*/