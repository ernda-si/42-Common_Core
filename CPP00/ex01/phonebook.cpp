/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:04:11 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/30 02:07:40 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static std::string	to_string(int nb) {
	std::stringstream	stream;
	std::string			value;
	
	stream << nb;
	value = stream.str();
	return (value);
}

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
		contacts[i].handle_format(to_string(i));
		contacts[i].print_all();
		i++;
	}
	display_index();
}

void	Phonebook::display_index() {
	std::string input;
	int i = 0;
	int	j = 0;

	while (true)
	{
		i = 0;
		j = 0;
		input = handle_input("Enter the contact index");
		if (input.empty())
			return;
		while (input[j])
		{
			while (input[j] == ' ' || (input[i] >= 9 && input[i] <= 13))
				input.erase(j, 1);
			j++;
		}
		if (input.size() >= 2 || input[i] < '0' || input[i] > '7')
			std::cout << "Value must be a single digit integer where 0 <= i <= 7" << std::endl;
		else if (input[i] - '0' >= this->total)
			std::cout << "Index doens't exist" << std::endl;
		else
			break;
	}
	contacts[input[i] - '0'].print_fields();
}

void	Phonebook::add_cmd() {
	std::string input;
	
	if (this->index >= 8)
		this->index = 0;

	input = handle_input("first_name");
	if (input.empty()) return;
	contacts[this->index].add_f1(input);

	input = handle_input("last_name");
	if (input.empty()) return;
	contacts[this->index].add_f2(input);

	input = handle_input("nickname");
	if (input.empty()) return;
	contacts[this->index].add_f3(input);

	input = handle_input("phone_number");
	if (input.empty()) return;
	contacts[this->index].add_f4(input);

	input = handle_input("darkest_secret");
	if (input.empty()) return;
	contacts[this->index].add_f5(input);

	this->index++;
	if (total < 8)
		this->total++;
}

std::string	Phonebook::handle_input(const std::string& field) const {
	std::string	input;
	int			i = 0;

	std::cout << field << ": " << std::flush;
	while (getline(std::cin, input)) {
		while(input[i] == ' ')
		{
			input.erase(i, 1);
			if (input[i] != ' ' || (input[i] >= 9 && input[i] <= 13))
				break;
		}
		if (!input.empty())
			return (input);
		std::cout << field << ": " << std::flush;
	}
	return ("");
}

Phonebook::Phonebook () {
	index = 0;
	total = 0;
}
