/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:03:41 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/16 13:03:56 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void) 
{
	Phonebook	phonebook;
	std::string	input;
	
	while (input != "EXIT")
	{
		std::cout << "enter a command: ";
		std::cin >> input;
		if (input == "ADD")
			phonebook.add_info();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "PRINT")
			phonebook.print_contact();
	}
	return (0);
}