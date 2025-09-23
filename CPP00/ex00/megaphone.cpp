/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:37:34 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/23 17:29:13 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static char	*ft_toupper(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	main(int ac, char *av[])
{
	int	i;

	i = 1;
	if (!av[i])
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < ac)
	{
		std::cout << ft_toupper(av[i]);
		i++;
	}
	std::cout << std::endl;
}
