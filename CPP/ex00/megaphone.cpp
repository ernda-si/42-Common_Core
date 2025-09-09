/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:50:46 by eve               #+#    #+#             */
/*   Updated: 2025/09/08 16:41:43 by eve              ###   ########.fr       */
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
	if (ac != 2)
	{
		std::cout << "Invalid number of arguments!" << std::endl;
		return (1);
	}
	std::cout << ft_toupper(av[1]);
}
