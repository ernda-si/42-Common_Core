/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:15:04 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/01 14:15:06 by ernda-si         ###   ########.fr       */
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
