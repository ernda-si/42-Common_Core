/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:48:15 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/18 14:56:05 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*s2;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	while (s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/* int	main(int ac, char **av)
{
	(void) ac;

	printf("Original strdup: %s\n", strdup(av[1]));
	printf("My strdup: %s\n", ft_strdup(av[1]));
} */