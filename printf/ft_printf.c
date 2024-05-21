/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:41:46 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/21 18:22:59 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
			write (1, &str[i], 1);
			i++;
	}
	return (0);
}

int	ft_putchar(char c)
{
		write(1, &c, 1);
		return (1);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb > 9 || nb < -9)
		i += ft_putnbr(nb / 10);
	else if (nb < 0)
		i += write (1, "-", 1);
	i += write(1, &"0123456789"[nb % 10 * ((nb > 0) - (nb < 0))], 1);
	return (i);
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
	va_list		ptr;
	char		token[1024] = {0};
	int			i;
	int			j;
	int			count;

	va_start	(ptr, str);
	i = 0;
	j = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[j])
	{
		token[i++] = str[j++];
		count++;
		if (str[j + 1] == '%' || str[i + 1] == '\0')
		{
			token[i] = '\0';
			i = 0;
			if (token[0] != '%')
				write(1, token, ft_strlen(token));
			else
			{
				while (token[j++])
				{
					if (token[j] == 'c' || token[j] == 'C')
					{
						ft_putchar(va_arg(ptr, int));
						count++;
					}
					else if (token[j] == 'd' || token[j] == 'D' || token[j] == 'i')
						count += ft_putnbr(va_arg(ptr, int));
					else if (token[j] == 's' || token[j] == 'S')
						count += ft_strlen(ft_putstr(va_arg(ptr, char *)));
					else if (token[j] == 'p')
					{
						write(1, va_arg(ptr, int *), 3);
						count++;
					}
				}
			}
		}
	}
	va_end(ptr);
	return (count);//{sS} {p} {dDi} oO uU xX {cC}
}

int	main(void)
{
	// int		i = 42;
	void	*p;

	p = "a";
	ft_printf("My printf: %p\n", p);
	printf("Original printf: %p\n", p);
}