/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:51 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/03 21:32:51 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat constructor called" << std::endl;
	type = "cat";
}

Cat::~Cat()
{
	std::cout << "Default Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) , Brain(copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Copy Cat assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat just Meowed" << std::endl;
}

std::string Cat::getType() const
{
	return type;
}