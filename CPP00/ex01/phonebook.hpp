/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:37:53 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/30 02:05:09 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class	Phonebook {

private:

	Contact		contacts[8];
	int			index;
	int			total;

public:

	Phonebook ();

	~Phonebook () {};

	std::string	handle_input(const std::string& field) const;

	void	add_cmd();

	void	search_cmd();

	void	display_index();

};

#endif
