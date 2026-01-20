/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:50 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/18 16:18:39 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog constructor called" << std::endl;
	type = "dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		type = other.type;
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Default Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
