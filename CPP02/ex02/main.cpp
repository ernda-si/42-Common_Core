	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:59:23 by ernda-si          #+#    #+#             */
/*   Updated: 2025/11/14 20:13:24 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a:	" << a << std::endl;

	std::cout << "++a:	" << ++a << std::endl;
	std::cout << "a:	" << a << std::endl;

	std::cout << "a++:	" << a++ << std::endl;
	std::cout << "a:	" << a << std::endl;

	std::cout << "--a:	" << --a << std::endl;
	std::cout << "a:	" << a << std::endl;

	std::cout << "a--:	" << a-- << std::endl;
	std::cout << "a:	" << a << std::endl;

	std::cout << "b:	" << b << std::endl;

	std::cout << "a / b:	" << a / b << std::endl;
	std::cout << "a * b:	" << a * b << std::endl;

	std::cout << "a:	" << a << std::endl;
	std::cout << "b:	" << b << std::endl;
	std::cout << "a + b:	" << a + b << std::endl;
	std::cout << "b - a:	" << a - b << std::endl;

	std::cout << "max:	" << Fixed::max( a, b ) << std::endl;
	std::cout << "min:	" << Fixed::min( a, b ) << std::endl;

	std::cout << "a < b:	" << (a < b) << std::endl;
	std::cout << "b < a:	" << (b < a) << std::endl;

	std::cout << "a > b:	" << (a > b) << std::endl;
	std::cout << "b > a:	" << (b > a) << std::endl;

	std::cout << "a <= b:	" << (a <= b) << std::endl;
	std::cout << "b <= a:	" << (b <= a) << std::endl;
	
	std::cout << "a >= b:	" << (a >= b) << std::endl;
	std::cout << "b >= a:	" << (b >= a) << std::endl;
	
	std::cout << "a = b" << std::endl;
	std::cout << "a:	" << a << std::endl;
	std::cout << "b:	" << b << std::endl;

	std::cout << "a <= b:	" << (a <= b) << std::endl;
	std::cout << "b <= a:	" << (b <= a) << std::endl;
	
	std::cout << "a >= b:	" << (a >= b) << std::endl;
	std::cout << "b >= a:	" << (b >= a) << std::endl;

	std::cout << "a == b:	" << (a == b) << std::endl;
	std::cout << "a != b:	" << (a != b) << std::endl;

	a = b;
	std::cout << "a is now equal b" << std::endl;
	std::cout << "a = b" << std::endl;
	std::cout << "a:	" << a << std::endl;
	std::cout << "b:	" << b << std::endl;

	std::cout << "a <= b:	" << (a <= b) << std::endl;
	std::cout << "b <= a:	" << (b <= a) << std::endl;
	
	std::cout << "a >= b:	" << (a >= b) << std::endl;
	std::cout << "b >= a:	" << (b >= a) << std::endl;

	std::cout << "a == b:	" << (a == b) << std::endl;
	std::cout << "a != b:	" << (a != b) << std::endl;

	return 0;
}

// Add public member functions to your class to overload the following operators:

// • The 6 comparison operators: >, <, >=, <=, ==, and !=.

// • The 4 arithmetic operators: +, -, *, and /.

// • The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
// post-decrement) operators, which will increase or decrease the fixed-point value by
// the smallest representable ϵ, such that 1 + ϵ > 1.
// Add these four public overloaded member functions to your class:

// • A static member function min that takes two references to fixed-point numbers as
// parameters, and returns a reference to the smallest one.

// • A static member function min that takes two references to constant fixed-point
// numbers as parameters, and returns a reference to the smallest one.

// • A static member function max that takes two references to fixed-point numbers as
// parameters, and returns a reference to the greatest one.

// • A static member function max that takes two references to constant fixed-point
// numbers as parameters, and returns a reference to the greatest one.

// $> ./a.out
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016
// $>
