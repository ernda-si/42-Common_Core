/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:04:11 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/23 18:49:40 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Phonebook::search_cmd() {
	int	i;

	i = 0;
	if (contacts[i].is_empty())
	{
		std::cout << "No contact available!" << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	while (i < 8 && !(contacts[i].is_empty()))
	{
		contacts[i].handle_format(std::to_string(i));
		contacts[i].print_all();
		i++;
	}
	display_index();
}

void	Phonebook::display_index() {
	std::string input;
	int i = 0;

	while (true)
	{
		i = 0;
		input = handle_input("Enter the contact index");
		std::cout << i << std::endl;
		std::cout << input[i] << std::endl;
		if (input.size() >= 2 || input[i] < '0' || input[i] > '7')
			std::cout << "Value must be a single digit integer where 0 <= i <= 7" << std::endl;
		else if (input[i] - '0' >= this->index)
			std::cout << "Index doens't exist" << std::endl;
		else
			break;
	}
	contacts[input[i] - '0'].print_fields();
}

void	Phonebook::add_cmd() {
	if (this->index >= 8)
		this->index = 0;
	contacts[this->index].add_f1(handle_input("first_name"));
	contacts[this->index].add_f2(handle_input("last_name"));
	contacts[this->index].add_f3(handle_input("nickname"));
	contacts[this->index].add_f4(handle_input("phone_number"));
	contacts[this->index].add_f5(handle_input("darkest_secret"));
	this->index++;
}

std::string	Phonebook::handle_input(std::string field) const {
	std::string	input;

	while (true) {
		std::cout << field << ": " << std::flush;
		getline(std::cin, input);
		if (!input.empty()) {
			return (input);
		}
	}
}
