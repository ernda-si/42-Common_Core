/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:27:30 by ernda-si          #+#    #+#             */
/*   Updated: 2025/12/27 22:31:18 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	type = "wrong cat";
}

WrongCat::~WrongCat()
{
	std::cout << "Default WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Copy WrongCat assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat just barked" << std::endl;
}

std::string WrongCat::getType() const
{
	return type;
}
