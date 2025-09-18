/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:20:27 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/18 15:05:53 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

# include "contact.hpp"

void	print_format(std::string str);
int		ft_atoi(std::string str);

class Phonebook { 

private:

	Contact		contact[9];
	static int	index;

public:

	void	add_info(void);

	// void	print_contact(void) const;

	void	search(void) const;
};

#endif
