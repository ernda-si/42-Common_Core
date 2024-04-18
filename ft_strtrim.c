/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:22:29 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/18 19:14:59 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	char *s2;
	
	i = 0;
	j = 0;
	s2 = (char *)malloc(sizeof(char) * strlen(s1) + 1);
	if(s2 == 0)
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == set[j] && set[j] != '\0')
		{
			j++;
			i++;
		}
	s2[i] = s1[i];
	i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	main(int ac, char **av)
{
	(void) ac;
	printf("Old str: %s\n", av[1]);
	printf("New str: %s\n", ft_strtrim(av[1], av[2]));
}