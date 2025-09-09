/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:50:20 by eve               #+#    #+#             */
/*   Updated: 2025/09/08 22:50:12 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int Phonebook::i = 0;

void	print_format(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << std::right << str << "|";

}

int     ft_atoi(std::string str)
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

int main(void) 
{
	Phonebook phonebook;
	std::string input;
	
	while (input != "EXIT")
	{
		std::cout << "enter a command: ";
		std::cin >> input;
		if (input == "ADD")
			phonebook.add_info();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "PRINT")
			phonebook.print_contact();
	}
	return (0);
}
