/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:02:48 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/10 15:58:50 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str1, char const *str2, int len)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (str2[0] == '\0')
		return (str1);
	if (len < 0)
		len = ft_strlen(str1);
	while (str1[i] != '\0' && i < len)
	{
		while ((str1[i] == str2[i2] || str2[i2] == '\0') && i < len)
		{
			if (str2[i2] == '\0')
				return (&str1[i - i2]);
			i2++;
			i++;
		}
		i++;
		i2 = 0;
	}
	return (NULL);
}
/* 2, 8, 10, 12
int main(void)
{
	char haystack[] = "lorem ipsum dolor sit amet";
	char needle[] = "dolor";
	printf("%s\n", ft_strnstr(haystack, needle, 50));
	return (0);
}*/