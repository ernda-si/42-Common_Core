/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:10:01 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/23 16:33:37 by ernda-si         ###   ########.fr       */
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
    }

    Fixed &operator=(const Fixed& obj) {
        std::cout << "Assignment operator called" << std::endl;
    }

    void    getRawBIts() {
        
    };

};

#endif