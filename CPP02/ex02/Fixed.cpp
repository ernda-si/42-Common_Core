/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:49:08 by eve               #+#    #+#             */
/*   Updated: 2025/11/12 21:00:13 by eve              ###   ########.fr       */
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

Fixed   &Fixed::operator++()
{
	_fixed++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;

	++(*this);
	return (old);
}

Fixed	Fixed::operator*()
{
	
}
