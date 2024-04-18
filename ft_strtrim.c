/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:51:31 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/18 18:05:53 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int j;
	int k;
	char *s2;

	s2 = (char *)s1;
	i = 0;
	j = 0;
	k = 0;
	while (*s1)
	{
		while (s2[i] != set[j] && set[j] != '\0')
		{
			j++;
			if (s1[i] == set[j])
			{
				j = 0;
				i++;
				k++;
			}
		}
		j = 0;
		s2[i] = s1[i];
		i++;
	}
	//s2 = (char *)malloc(sizeof(char) * (i - k));
	return (s2);
}
int	main(int ac, char **av)
{
	(void) ac;
	printf("strtrim: %s", ft_strtrim(av[1], av[2]));
}