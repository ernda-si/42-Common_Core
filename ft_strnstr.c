/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:02:48 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/15 13:16:22 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str1, char *str2, int len)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (str2[0] == '\0')
		return (str1);
	while (str1[i] != '\0' && i < (len - 1))
	{
		while (str1[i] == str2[i2] || str2[i2] == '\0')
		{
			i2++;
			i++;
			if (str2[i2] == '\0')
				return (&str1[i - i2]);
		}
		i++;
		i2 = 0;
	}
	return ("NULL");
}

/* int	main(void)
{
	printf("%s\n", ft_strnstr("acbacaxi", "ca", 9));
} */
