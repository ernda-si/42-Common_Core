/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:20:52 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/18 15:05:59 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

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

	int	print_info(void) const;
};

#endif