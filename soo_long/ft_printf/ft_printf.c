/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:24:59 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/16 13:25:11 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += write (1, "(null)", 6);
		return (i);
	}
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putnbr(int nb)
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

static int	ft_handler(const char *str, va_list args, int len)
{
	if (*str == 'i' || *str == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (*str == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (*str == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (*str == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (*str == 'X')
		len += ft_puthexabig(va_arg(args, unsigned int));
	else if (*str == 'x')
		len += ft_puthexasmall(va_arg(args, unsigned int));
	else if (*str == 'p')
		len += ft_puthexadress(va_arg(args, unsigned long));
	else if (*str == '%')
		len += write (1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str != '%')
			len += write(1, str, 1);
		else
		{
			str++;
			len = ft_handler(str, args, len);
		}
		str++;
	}
	va_end(args);
	return (len);
}
