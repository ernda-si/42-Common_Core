/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:01:42 by ernda-si          #+#    #+#             */
/*   Updated: 2025/11/14 20:13:03 by ernda-si         ###   ########.fr       */
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
	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	Fixed	operator*(const Fixed other)
	{
		return (this->toFloat() * other.toFloat());
	}

	Fixed	operator/(const Fixed other)
	{
		return (this->toFloat() / other.toFloat());
	}

	Fixed	operator+(const Fixed other)
	{
		return (this->toFloat() + other.toFloat());
	}

	Fixed	operator-(const Fixed other)
	{
		return (this->toFloat() - other.toFloat());
	}

	static float	max(const Fixed &a, const Fixed &b)
	{
		return (a.toFloat() > b.toFloat() ? a.toFloat() : b.toFloat());
	}

	static float	min(const Fixed &a, const Fixed &b)
	{
		return (a.toFloat() < b.toFloat() ? a.toFloat() : b.toFloat());
	}

	bool	operator<(const Fixed &other) const
	{
		return (this->toFloat() < other.toFloat());
	}

	bool	operator>(const Fixed &other) const
	{
		return (this->toFloat() > other.toFloat());
	}
	
	bool	operator<=(const Fixed &other) const
	{
		return (this->toFloat() <= other.toFloat());
	}

	bool	operator>=(const Fixed &other) const
	{
		return (this->toFloat() >= other.toFloat());
	}

	bool	operator==(const Fixed &other) const
	{
		return (this->toFloat() == other.toFloat());
	}

	bool	operator!=(const Fixed &other) const
	{
		return (this->toFloat() != other.toFloat());
	}

};

#endif
