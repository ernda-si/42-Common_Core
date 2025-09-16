/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:51:13 by eve               #+#    #+#             */
/*   Updated: 2025/09/16 13:55:43 by ernda-si         ###   ########.fr       */
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

	Contact		contact[9];
	static int	index;

	public:

	void	add_info(void);

	void	print_contact(void) const;

	void	search(void) const;
};

#endif
