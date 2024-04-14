/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:15:20 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/10 12:35:08 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *str1, char *str2, int n)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && i < (n - 1))
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

int	main(void)
{
	printf("%d\n", ft_strncmp("abc", "abd", 2));
}

