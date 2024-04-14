/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:54:57 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/13 17:22:39 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	char	*vs;

	*vs = s;
	while (s && n--)
	{
		*vs = '\0';
	}
}

int	main(void)
{
	int	i;
	char	s[] = "Abacaxi";
	bzero (s + 3, sizeof(char) * 3);
	printf("Original: %s\n", s);

	char	s2[] = "Abacaxi";
	ft_bzero(s2 + 3, sizeof(char) * 3);
	printf("My bzero: %s\n", s2);
}

