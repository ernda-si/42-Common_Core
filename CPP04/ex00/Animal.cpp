/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:52 by ernda-si          #+#    #+#             */
/*   Updated: 2025/12/27 22:28:26 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Copy Animal assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "No animal specified" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}