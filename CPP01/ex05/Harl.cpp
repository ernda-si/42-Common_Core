/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:37:39 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/15 16:15:52 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_Debug(void) {
	std::cout << "DEBUG level message called" << std::endl;
}

void	Harl::_Info(void) {
	std::cout << "INFO level message called" << std::endl;
}

void	Harl::_Warning(void) {
	std::cout << "WARNING level message called" << std::endl;
}

void	Harl::_Error(void) {
	std::cout << "ERROR level message called" << std::endl;
}

void	Harl::complain( std::string level ) {
	std::string	array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*functions[])() = {
		&Harl::_Debug, &Harl::_Info,
		&Harl::_Warning, &Harl::_Error
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == array[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "Not a valid level" << std::endl;
}
