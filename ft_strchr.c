/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:51:43 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/19 11:26:26 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i] != c)
	{
		if (str[i] == '\0' && str[i] != c)
			return ("NULL");
	}
	if (str[i] == c)
		return (&str[i]);
	return ("NULL");
}
// 4th test failed //
/* int	main(void)
{
	printf("%s\n", ft_strchr("aa", ' '));
} */
