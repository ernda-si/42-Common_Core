/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:03:30 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/29 17:10:06 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <stdlib.h>
# include <sstream>

class	Contact {

private:

	std::string first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:

	void	add_f1(std::string name);

	void	add_f2(std::string name);

	void	add_f3(std::string name);

	void	add_f4(std::string name);

	void	add_f5(std::string name);

	void	print_fields() const;
	
	void	handle_format(std::string field) const;

	void	print_all();

	bool	is_empty();

};

#endif
