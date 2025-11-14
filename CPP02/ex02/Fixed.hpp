/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:01:42 by ernda-si          #+#    #+#             */
/*   Updated: 2025/11/11 16:35:14 by eve              ###   ########.fr       */
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

};

#endif