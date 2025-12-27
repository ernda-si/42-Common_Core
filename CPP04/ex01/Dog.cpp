/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:50 by ernda-si          #+#    #+#             */
/*   Updated: 2025/12/27 22:28:38 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called" << std::endl;
	type = "dog";
}

Dog::~Dog()
{
	std::cout << "Default Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Copy Dog assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog just barked" << std::endl;
}

std::string Dog::getType() const
{
	return type;
}