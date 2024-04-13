/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:23:29 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/13 18:00:11 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	if (*dst++)
	{
		
	}
}

int	main(void)
{
	printf("Original strlcat: %i\n", strlcat("Abacaxi", "Uva", sizeof(char) * 0));
	printf("My strlcat: %i\n", ft_strlcat("Abacaxi", "Uva", sizeof (char) * 0));
}