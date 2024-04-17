/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:39:45 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/17 19:28:27 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	int	len1;
	int	len2;
	int	len3;
	int	i;
	int	i2;
	char *s3;

	len1 = 0;
	len2 = 0;
	i = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	s3 = (char*)malloc(sizeof(char) * (len1 + len2));
	len3 = len2 + len1;
	while (len3-- && i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (len3-- && i2 < len2)
	{
		s3[i] = s2[i2];
		i2++;
	}
	return (s3);
}

int	main(void)
{
	char *ts = "test";
	char *ts2 = "abacaxi";

	printf("Original strjoin: %s\n", ft_strjoin(ts, ts2));
}