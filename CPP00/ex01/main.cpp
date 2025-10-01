/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:37:50 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/01 14:12:48 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string input;
	Phonebook phonebook;

	std::cout << "Input: " << std::flush;
	while (getline(std::cin, input))
	{
		if (input == "ADD")
			phonebook.add_cmd();
		else if (input == "SEARCH")
			phonebook.search_cmd();
		else if (input == "EXIT")
			break;
		if (!std::cin.eof())
			std::cout << "Input: " << std::flush;
	}
}
