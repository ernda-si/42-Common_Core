/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:26:15 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/16 14:56:47 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

/* int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	printf ("char: %c\n", ft_putchar_fd(NULL, 1));
} */