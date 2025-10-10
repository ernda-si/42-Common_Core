/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:03 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 16:38:09 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int     ft_atoi(std::string str)
{
	int     i;
	int     signal;
	long    num;
	i = 0;
	signal = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i++] - '0';
	}
	if (num * signal >= -2147483648 && num * signal <= 2147483647) 
		return (signal * num);
	return (0);
}

int main(int ac, char *av[])
{
	Zombie      *zh;
	int         i;
	int			n;

	n = ft_atoi(av[1]);
	i = -1;
	if (ac != 3)
		return (0);
	zh = zombieHorde(n, av[2]);
	while (++i < n)
		zh[i].announce();
	delete[] zh;

	return 0;
}
