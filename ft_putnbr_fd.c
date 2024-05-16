/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:55:07 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/16 14:34:50 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write (fd, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", fd);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-', fd);
			nb *= -1;
		}
		if (nb <= 9)
		{
			ft_putchar(nb + '0', fd);
		}
		if (nb >= 10)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
	}
}

/*
int	main(void)
{
	ft_putnbr_fd(2147483647);
	write(1, "\n", 1);
	ft_putnbr_fd(-2147483648);
	write(1, "\n", 1);
	ft_putnbr_fd(-42);
	write(1, "\n", 1);
	ft_putnbr_fd(0);
	write(1, "\n", 1);
	ft_putnbr_fd(402);
	write(1, "\n", 1);
	ft_putnbr_fd(10);
	write(1, "\n", 1);
	ft_putnbr_fd(-10);
}
*/