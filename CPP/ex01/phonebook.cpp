/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:20:16 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/18 13:37:18 by ernda-si         ###   ########.fr       */
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

// void	Phonebook::print_contact(void) const {
// 	std::string input;
// 	int			nb;

// 	std::cout << "Enter contact number: ";
// 	getline(std::cin, input);
// 	nb = ft_atoi(input);
// 	if (nb >= 0 && nb <= 8)
// 		contact[nb].print_info();
// }

void	Phonebook::add_info(void) { 
	std::string input;

	if (Phonebook::index >= 8)
		Phonebook::index = 0;
	std::cout << "Enter first name: ";
	getline(std::cin, input);
	contact[index].add_first(input);
	std::cout << "Enter last name: ";
	getline(std::cin, input);
	contact[index].add_last(input);
	std::cout << "Enter nickname: ";
	getline(std::cin, input);
	contact[index].add_nick(input);
	std::cout << "Enter phone_number: ";
	getline(std::cin, input);
	contact[index].add_phone(input);
	std::cout << "Enter darkest_secret: ";
	getline(std::cin, input);
	contact[index].add_secret(input);
	std::cout << "Contact saved!" << std::endl;
	Phonebook::index++;
}
