	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   Fixed.hpp                                          :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2025/11/06 18:01:42 by ernda-si          #+#    #+#             */
	/*   Updated: 2025/11/14 17:46:23 by ernda-si         ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

	#ifndef FIXED_HPP
	#define FIXED_HPP

	# include <iostream>
	# include <cmath>
	# include <string>

	class Fixed
	{
	private:
		
		static const int    _fractionalBits = 8;
		int                 _fixed;

	public:

		Fixed();

		Fixed(const int number);

		Fixed(const float number);

		~Fixed();

		Fixed(const Fixed &other);

		Fixed &operator=(const Fixed &other);

		int		toInt( void ) const;

		float	toFloat( void ) const;

		friend	std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

		float	static max(const Fixed &a, const Fixed &b)
		{
			return (a.toFloat() < b.toFloat() ? a.toFloat() : b.toFloat());
		}

	};

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

	#endif