/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:24:59 by ernda-si          #+#    #+#             */
/*   Updated: 2024/06/06 19:00:09 by ernda-si         ###   ########.fr       */
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

// int	main(void)
// {
// 	printf("Org %d\n", (int)-2147483648);
// 	ft_printf("Cpy %d\n", (int)-2147483648);
// }

// int	main(void) {
// 	int		nb;
// 	char	*str;

// 	str = "test";
// 	nb = 42;
// ft_printf("my printf len: %d\n", ft_printf("Mprintf: %d %i %c %s %u %x %X\n", nb, nb, nb, str, 2147483647, 123, 123));
// }

/* int	main(void)
{
	int		nb;
	char	*str;

	str = "test";
	nb = 42;
	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %d %i %c %s %u %x %X\n", nb, nb, nb, str, 2147483647, 123, 123));
	printf("original printf len: %d\n", printf("Oprintf: %d %i %c %s %u %x %X\n", nb, nb, nb, str, 2147483647, 123, 123));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %d\n", nb));
	printf("original printf len: %d\n", printf("Oprintf: %d\n", nb));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %i\n", nb));
	printf("original printf len: %d\n", printf("Oprintf: %i\n", nb));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %c\n", nb));
	printf("original printf len: %d\n", printf("Oprintf: %c\n", nb));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %s\n", str));
	printf("original printf len: %d\n", printf("Oprintf: %s\n", str));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %u\n", 2147483647));
	printf("original printf len: %d\n", printf("Oprintf: %u\n", 2147483647));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %x\n", -123));
	printf("original printf len: %d\n", printf("oprintf: %x\n", -123));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %X\n", -123));
	printf("original printf len: %d\n", printf("Oprintf: %X\n", -123));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %p\n", -123));
	printf("original printf len: %d\n", printf("Oprintf: %p\n", -123));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %%\n"));
	printf("original printf len: %d\n", printf("Oprintf: %%\n"));

	ft_printf("my printf len: %d\n", ft_printf("%s %d\n", NULL, 123));
	printf("original printf len: %d\n", printf("%s %d\n", NULL, 123));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %x\n", -123));
	printf("original printf len: %d\n", printf("oprintf: %x\n", -123));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %X\n", -123));
	printf("original printf len: %d\n", printf("Oprintf: %X\n", -123));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %p\n", 0));
	printf("original printf len: %d\n", printf("Oprintf: %p\n", 0));

	ft_printf("my printf len: %d\n", ft_printf("Mprintf: %%\n"));
	printf("original printf len: %d\n", printf("Oprintf: %%\n"));

	ft_printf("my printf len: %d\n", ft_printf("%s %d\n", NULL, 123));
	printf("original printf len: %d\n", printf("%s %d\n", NULL, 123));
} */

/*%c Prints a single character.-----
• %s Prints a string (as defined by the common C convention).-----
• %p The void * pointer argument has to be printed in hexadecimal format. -----
• %d Prints a decimal (base 10) number.-----
• %i Prints an integer in base 10.-----
• %u Prints an unsigned decimal (base 10) number.-----
• %x Prints a number in hexadecimal (base 16) lowercase format.-----
• %X Prints a number in hexadecimal (base 16) uppercase format.-----int	main(void)
• %% Prints a percent sign.----- */