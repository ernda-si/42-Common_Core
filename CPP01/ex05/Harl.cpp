/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:37:39 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 17:00:06 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my \
		7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" \
			<< std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. \
		You didn’t put enough bacon in my burger! If you did, I wouldn’t \
			be asking for more!" \
				<< std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. \
		I’ve been coming for years, whereas you started working here \
			just last month." \
				<< std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." \
		<< std::endl;
}

void	Harl::complain( std::string level ) {
	std::string	array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*functions[])() = {
		&Harl::debug, &Harl::info,
		&Harl::warning, &Harl::error
	};
	for (int i = 0; level != array[i]; i++)
	{
		if (level == array[i])
			return (void)(std::cout << functions[i] << std::endl);
	}
}
