/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:51:13 by eve               #+#    #+#             */
/*   Updated: 2025/09/08 22:50:55 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include <iostream>
#include <iomanip>
#include <string>


void		print_format(std::string str);
int			ft_atoi(std::string str);

class Contact {

	private:
	
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	
	public:
	
	void	add_first(std::string new_first) {
		first_name = new_first;
	}

	void	add_last(std::string new_last) {
		last_name = new_last;
	}

	void	add_nick(std::string new_nick) {
		nickname = new_nick;
	}

	void	add_phone(std::string new_phone) {
		phone_number = new_phone;
	}

	void	add_secret(std::string new_secret) {
		darkest_secret = new_secret;
	}

	bool exists(void) const {
		return (!first_name.empty());
	}

	int	print_info(void) const {
		print_format(first_name);
		print_format(last_name);
		print_format(nickname);
		std::cout << std::endl;
		return (1);
	}
};

class Phonebook { 

	private:

	Contact 	contact[9];
	static int	i;

	public:

void add_info(void) { 
	std::string input; 

	i++;
	if (i >= 8) 
		i = 0; 
	std::cout << "Enter first name: "; 
	std::cin >> input; 
	contact[i].add_first(input); 
	std::cout << "Enter last name: "; 
	std::cin >> input; contact[i].add_last(input); 
	std::cout << "Enter nickname: "; 
	std::cin >> input; 
	contact[i].add_nick(input); 
	std::cout << "Enter phone_number: "; 
	std::cin >> input; 
	contact[i].add_phone(input); 
	std::cout << "Enter darkest_secret: "; 
	std::cin >> input; 
	contact[i].add_secret(input); 
	std::cout << "Contact saved!" << std::endl;
}

	void	print_contact(void) const {
		std::string input;
		int			nb;

		std::cout << "Enter contact number: ";
		std::cin >> input;
		nb = ft_atoi(input);
		if (nb > 0 && nb <= 8)
			contact[nb].print_info();
	}

	void	search(void) const {
		int	nb = 0;

		std::cout << "     index|first name| last name|  nickname|" << std::endl;
		while (++nb >= 0 && nb <= 8)
		{
			if (contact[nb].exists())
				break;
			print_format(std::to_string(nb));
			contact[nb].print_info();
		}
	}
};

#endif
