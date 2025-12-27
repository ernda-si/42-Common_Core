/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:51 by ernda-si          #+#    #+#             */
/*   Updated: 2025/12/27 22:28:26 by ernda-si         ###   ########.fr       */
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

Cat::Cat(const Cat &copy) : Animal(copy)
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