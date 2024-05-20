/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:41:46 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/20 16:52:18 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
			write (1, &str[i], 1);
			i++;
	}
}

char	ft_putchar(char c)
{
		write(1, &c, 1);
		return(c);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
			ft_putstr("-2147483648");
	}
	else
	{
			if (nb < 0)
			{
					ft_putchar('-');
					nb *= -1;
			}
			if (nb <= 9)
			{
					ft_putchar(nb + '0');
			}
			if (nb >= 10)
			{
					ft_putnbr(nb / 10);
					ft_putnbr(nb % 10);
			}
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list ptr;
	va_start (ptr, str);

	char	token[1000];
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[j])
	{
		token[i++] = str[j++];
		if (str[j + 1] == '%' || str[i + 1] == '\0')
		{
			token[i] = '\0';
			i = 0;
			if (token[0] != '%')
			{
				write(1, token, ft_strlen(token));
			}
			else
			{
				while (token[j++])
					if (token[j] == 'c')
						ft_putchar(token[j]);
			}
		}
	}
	return (0);
}

int	main(void)
{
	int	a = 42;
	ft_printf("My printf: %c\n", a);
	printf("Original printf: %c\n", a);
}