/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:31:30 by ernda-si          #+#    #+#             */
/*   Updated: 2025/12/17 17:39:30 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"

class   Dog : public Animal {

private:

protected:

public:

	Dog() {
		std::cout << "Default Dog constructor called" << std::endl;
	}

	~Dog() {
		std::cout << "Default Dog destructor called" << std::endl;
	}

	Dog &operator=(const Dog &other) {
		std::cout << "Copy Dog assignment operator called" << std::endl;

		if (this != &other)
			type = other.type;
		return *this;
	}

	Dog(Dog &copy) {
		std::cout << "Copy Dog constructor called" << std::endl;

		*this = copy;
		type = copy.type;
	}

	void makeSound() {
		std::cout << "Dog just barked" << std::endl;
	}

	std::string getType () {
		return (type);
	}

};

#endif