/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:33:52 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/18 16:18:05 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Default Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return (type);
}
