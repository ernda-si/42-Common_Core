/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:37:53 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/26 13:43:42 by ernda-si         ###   ########.fr       */
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

	std::string	handle_input(std::string field) const;

	void	add_cmd();

	void	search_cmd();

	void	display_index();

};

#endif
