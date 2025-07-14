/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:59:35 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/16 14:18:35 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = 0;
	while (s[len])
		len++;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	while (s[i])
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*char to_uppercase(unsigned int index, char c)
{
	(void) index;
	if (c >= 'a' && c <= 'z')
		return c - 32;
	else
		return c;
}

 int	main(void)
{
	// char test_string[] = "Test!";
	char *result = ft_strmapi(NULL, &to_uppercase);

	if (result == NULL)
	{
		printf("Memory allocation failed or string does not exist.\n");
		return 1;
	}
	// printf("Original string: %s\n", test_string);
	printf("Mapped string: %s\n", result);
	free(result);
	return 0;
} */