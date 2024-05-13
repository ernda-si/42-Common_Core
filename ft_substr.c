/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:55:11 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/13 14:10:14 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;
	char	*nullstr;

	i = 0;
	if (len > ft_strlen(s) || ft_strlen(s) < len + start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
	{
		nullstr = (char *)malloc(sizeof(char) * 1);
		*nullstr = '\0';
		return (nullstr);
	}
	ss = (char *)malloc(sizeof(char) * len + 1);
	if (ss == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

/* int	main(void)
{
	char const *s2 = "Teste";
	unsigned int start2 = 1;
	size_t len2 = 3;
	printf("Old str: %s\n", "teste");
	printf("New str: %s\n", ft_substr(s2, start2, len2));
} */