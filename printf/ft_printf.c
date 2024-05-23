/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:24:59 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/23 19:04:33 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

static int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
			write (1, &str[i], 1);
			i++;
	}
	return (i);
}

static int	ft_putchar(char c)
{
		write(1, &c, 1);
		return (1);
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

static int	ft_puthexasmall(int nb)
{
	int	i;

	i = 0;
	if (nb > 9 || nb < -9)
		i += ft_puthexasmall(nb / 16);
	else if (nb < 0)
		i += write (1, "-", 1);
	i += write(1, &"0123456789abcdef"[nb % 16 * ((nb > 0) - (nb < 0))], 1);
	return (i);
}

static int	ft_puthexabig(int nb)
{
	int	i;

	i = 0;
	if (nb > 9 || nb < -9)
		i += ft_puthexabig(nb / 16);
	else if (nb < 0)
		i += write (1, "-", 1);
	i += write(1, &"0123456789ABCDEF"[nb % 16 * ((nb > 0) - (nb < 0))], 1);
	return (i);
}

static int	ft_putunbr(unsigned int unb)
{
	int	i;

	i = 0;
	if (unb > 9)
		i += ft_putunbr(unb / 10);
	i += write(1, &"0123456789"[unb % 10], 1);
	return (i);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int len;

	len = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str != '%')
			write(1, str, 1);
		else
		{
			*str++;
			// if (*str == 'd')
			// 	len += ft_putnbr(va_arg(args, double));
			if (*str == 'i' || *str == 'd')
				len += ft_putnbr(va_arg(args, int));
			else if (*str == 'c' || *str == 'C' || *str == '%')
				len += ft_putchar(va_arg(args, int));
			else if (*str == 's')
				len += ft_putstr(va_arg(args, char *));
			else if (*str == 'u')
				len += ft_putunbr(va_arg(args, unsigned int));
			else if (*str == 'x')
				len += ft_puthexasmall(va_arg(args, int));
			else if (*str == 'X')
				len += ft_puthexabig(va_arg(args, int));
		}
		*str++;
		len++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	int		nb;
	char	*str;

	str = "abacaxi";
	nb = 42;
	ft_printf("my printf len: %d\n", ft_printf("my printf: %d %i %c %s %u %x %X\n", nb, nb, nb, str, 2147483648, 123));
	printf("original printf len: %d\n", printf("original printf: %d %i %c %s %u %x %X\n", nb, nb, nb, str, 2147483648, 123));
}

/*%c Prints a single character.-----
• %s Prints a string (as defined by the common C convention).-----
• %p The void * pointer argument has to be printed in hexadecimal format. -----/////s
• %d Prints a decimal (base 10) number.-----
• %i Prints an integer in base 10.-----
• %u Prints an unsigned decimal (base 10) number.-----
• %x Prints a number in hexadecimal (base 16) lowercase format.-----
• %X Prints a number in hexadecimal (base 16) uppercase format.-----
• %% Prints a percent sign.----- */