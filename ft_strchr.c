/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:51:43 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/26 11:43:10 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *)s;
	while (str[++i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}
// 4th test failed //
/* int	main(void)
{
	printf("%s\n", ft_strchr("a a", ' '));
} */
