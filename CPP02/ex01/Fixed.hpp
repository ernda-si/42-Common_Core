/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:38:38 by ernda-si          #+#    #+#             */
/*   Updated: 2025/11/11 15:19:54 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

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


};

#endif