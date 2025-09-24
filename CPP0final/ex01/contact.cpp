/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:04:13 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/24 16:00:26 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Contact::add_f1(std::string name) {
	first_name = name;
}

void	Contact::add_f2(std::string name) {
	last_name = name;
}

void	Contact::add_f3(std::string name) {
	nickname = name;
}

void	Contact::add_f4(std::string name) {
	phone_number = name;
}

void	Contact::add_f5(std::string name) {
	darkest_secret = name;
}

void	Contact::handle_format(std::string field) const {
	if (field.size() >= 10)
		std::cout << field.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << std::right << field << "|";
}

void	Contact::print_all() {
	handle_format(first_name);
	handle_format(last_name);
	handle_format(nickname);
	std::cout << std::endl;
}

bool	Contact::is_empty() {
	return (first_name.empty());
}

void	Contact::print_fields() const {
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}
