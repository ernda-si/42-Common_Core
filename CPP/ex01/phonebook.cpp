/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:50:20 by eve               #+#    #+#             */
/*   Updated: 2025/09/16 14:04:41 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	Phonebook::index = 0;

void	Phonebook::search(void) const {
	int	nb = 0;

	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	while (nb >= 0 && nb <= 8)
	{
		if (!(contact[nb].exists()))
			break;
		print_format(std::to_string(nb));
		contact[nb].print_info();
		nb++;
	}
}

void	Phonebook::print_contact(void) const {
	std::string input;
	int			nb;

	std::cout << "Enter contact number: ";
	std::cin >> input;
	nb = ft_atoi(input);
	if (nb >= 0 && nb <= 8)
		contact[nb].print_info();
}

void	print_format(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << std::right << str << "|";

}

void	Phonebook::add_info(void) { 
	std::string input;

	if (Phonebook::index >= 8)
		Phonebook::index = 0;
	std::cout << "Enter first name: ";
	std::cin >> input; 
	contact[index].add_first(input);
	std::cout << "Enter last name: ";
	std::cin >> input; contact[index].add_last(input); 
	std::cout << "Enter nickname: ";
	std::cin >> input; 
	contact[index].add_nick(input);
	std::cout << "Enter phone_number: ";
	std::cin >> input; 
	contact[index].add_phone(input); 
	std::cout << "Enter darkest_secret: ";
	std::cin >> input; 
	contact[index].add_secret(input);
	std::cout << "Contact saved!" << std::endl;
	Phonebook::index++;
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
