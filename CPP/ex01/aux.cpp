/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:18:52 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/18 13:19:11 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	print_format(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << std::right << str << "|";
}

int	ft_atoi(std::string str)
{
	int		i;
	int		signal;
	long	num;

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
