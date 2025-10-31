/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:10:01 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/27 16:25:50 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed {

private:

    static const int    _fractionalBits = 8;
    int                 _fixed;

public:

    Fixed() {
        std::cout << "Default constructor called" << std::endl;
        _fixed = 0;
    }

    ~Fixed() {
        std::cout << "Destructor called" << std::endl;
    }

    Fixed(const Fixed &obj) {
        std::cout << "Copy constructor called" << std::endl;
        _fixed = obj._fixed;
    }

    Fixed &operator=(const Fixed& obj) {
        std::cout << "Assignment operator called" << std::endl;
        if (this != &obj)
            _fixed = obj._fixed;
        return *this;
    }

    int getRawBits( void ) const {
        
    }

    void setRawBits( int const raw ) {
        
    }

};

#endif