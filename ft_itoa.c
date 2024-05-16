/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:17:02 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/16 13:47:16 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*special_cases(int n)
{
	char	*str;
	char	*zero;
	int		i;
	char	*intmax;

	intmax = "-2147483648";
	i = -1;
	zero = "0";
	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		while (zero[++i] != '\0')
			str[i] = zero[i];
		str[i] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * 12);
	while (intmax[++i] != '\0')
		str[i] = intmax[i];
	str[i] = '\0';
	return (str);
}

int	ft_len(int num)
{
	int		len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		end;

	len = ft_len(n);
	end = len;
	if (n == 0)
		return (special_cases(n));
	if (n == -2147483648)
		return (special_cases(n));
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[--len] = '0' + (n % 10);
		n /= 10;
	}
	str[end] = '\0';
	return (str);
}

/* int	main(void)
{
	printf("itoa test: %s\n", ft_itoa(214748367));
	printf("itoa test: %s\n", ft_itoa(-2147483648LL));
	printf("itoa test: %s\n", ft_itoa(0));
	printf("itoa test: %s\n", ft_itoa('\0'));
	printf("itoa test: %s\n", ft_itoa(' '));
} */