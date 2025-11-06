/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:45:32 by ernda-si          #+#    #+#             */
/*   Updated: 2025/11/06 17:57:30 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixed = 0;
}

Fixed::Fixed(const int number)
{
	// _fixed = (number * (2 ^ _fractionalBits));
	_fixed = number * (1 << _fractionalBits);
}

Fixed::Fixed(const float number)
{
	// _fixed = (number * (2 ^ _fractionalBits))
	_fixed = roundf(number * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixed(other._fixed)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixed = other._fixed;
	return *this;
}

int Fixed::toInt( void ) const
{
	// return (_fixed / (2 ^ _fractionalBits));
	return (_fixed / (1 << _fractionalBits));
}

float   Fixed::toFloat( void ) const
{
	// return static_cast<float>(_fixed) / (2 ^ _fractionalBits);
	return static_cast<float>(_fixed) / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
