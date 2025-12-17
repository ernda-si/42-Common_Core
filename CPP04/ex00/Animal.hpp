/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:43:06 by ernda-si          #+#    #+#             */
/*   Updated: 2025/12/17 17:38:55 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

class   Animal {

private:

protected:

	std::string type;

public:

	Animal() {
		std::cout << "Default Animal constructor called" << std::endl;
	}

	~Animal() {
		std::cout << "Default Animal destructor called" << std::endl;
	}

	Animal &operator=(const Animal &other) {
		std::cout << "Copy Animal assignment operator called" << std::endl;

		if (this != &other)
			type = other.type;
		return *this;
	}

	Animal(Animal &copy) {
		std::cout << "Copy Animal constructor called" << std::endl;

		*this = copy;
		type = copy.type;
	}

};

#endif