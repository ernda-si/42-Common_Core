/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:50 by ernda-si          #+#    #+#             */
/*   Updated: 2026/03/06 14:20:03 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Default Dog destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	brain = new Brain(*copy.brain);
	type = copy.type;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Copy Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
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