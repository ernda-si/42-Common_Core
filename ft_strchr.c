/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:51:43 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/10 13:34:33 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *)s;
	while (str[++i] != (unsigned char)c)
	{
		if (str[i] == '\0')
			return (NULL);
	}
	return (&str[i]);
}

/* int	main(void)
{
	printf("%s\n", strchr("tripouille", '0'));
	printf("%s\n", ft_strchr("tripouille", '0'));
} */
