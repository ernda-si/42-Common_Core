/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:49:08 by eve               #+#    #+#             */
/*   Updated: 2026/01/05 14:48:31 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <climits>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixed = 0;
}

Fixed::Fixed(const int number)
{
	int	possibleInt = INT_MAX >> _fractionalBits;
	if (number > possibleInt || number < -possibleInt - 1)
	{
		std::cerr << "Integer overflow/underflow when converting to Fixed point representation." << std::endl;
		_fixed = 0;
		return ;
	}
	// _fixed = (number * (2 ^ _fractionalBits));
	_fixed = number * (1 << _fractionalBits);
}

Fixed::Fixed(const float number)
{
	if (std::isinf(number) || std::isnan(number) ||
		number > (static_cast<float>(INT_MAX) / (1 << _fractionalBits)) ||
		number < (static_cast<float>(INT_MIN) / (1 << _fractionalBits)))
	{
		std::cerr << "Float overflow/underflow when converting to Fixed point" << std::endl;
		_fixed = 0;
		return ;
	}
	// _fixed = (number * (2 ^ _fractionalBits))
	_fixed = roundf(number * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
    _fixed = other._fixed;
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

Fixed   &Fixed::operator--()
{
	_fixed--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;

	--(*this);
	return (old);
}

Fixed	Fixed::operator*(const Fixed other)
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed other)
{
	return (this->toFloat() / other.toFloat());
}

Fixed	Fixed::operator+(const Fixed other)
{
	return (this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed other)
{
	return (this->toFloat() - other.toFloat());
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() < b.toFloat() ? a : b);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}
