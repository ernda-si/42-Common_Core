/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:38:41 by ernda-si          #+#    #+#             */
/*   Updated: 2026/04/10 18:35:11 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a("test", 25);

	std::cout << "Bureaucrat " << a.getName() << " has " << a.getGrade() << std::endl;

	while (a.getGrade() < 251)
		a.DecreaseGrade();
	// while (a.getGrade() > -1)
		// a.increaseGrade();

	std::cout << "Bureaucrat " << a.getName() << " now has " << a.getGrade() << std::endl;

	try
	{
		if (a.getGrade() > 250)
			throw "Value is too low x > 250";
		else if (a.getGrade() < 1)
			throw "Value is too high x < 1";
	}
	catch(const char *e)
	{
		std::cout << "Exception caught: " << e << std::endl;
	}

}
