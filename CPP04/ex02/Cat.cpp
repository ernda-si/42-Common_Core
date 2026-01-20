/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:51 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/18 16:18:13 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	type = "cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
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

Cat::~Cat() {
	std::cout << "Default Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
