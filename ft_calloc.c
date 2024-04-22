/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:01:11 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/22 12:46:44 by ernda-si         ###   ########.fr       */
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

/* int	main(void)
{
	printf("Original calloc: %s\n", calloc(1, 1000));
	printf("My calloc: %s\n", ft_calloc(1, 1000));
} */