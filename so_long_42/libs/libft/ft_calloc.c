/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:01:11 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/10 15:54:54 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	s = malloc (nmemb * size);
	if (s == NULL)
		return (NULL);
	ft_bzero (s, nmemb * size);
	return (s);
}

/* int	main(void)
{
	printf("Original calloc: %s\n", (char *)calloc(-5, -5));
	printf("My calloc: %s\n", (char *)ft_calloc(-5, -5));
} */