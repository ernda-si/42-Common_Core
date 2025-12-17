/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:32:27 by ernda-si          #+#    #+#             */
/*   Updated: 2025/12/17 17:46:31 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"

class   Cat : public Animal {

private:

protected:

public:

	Cat() {
		std::cout << "Default Cat constructor called" << std::endl;

		type = "cat";
	}

	~Cat() {
		std::cout << "Default Cat destructor called" << std::endl;
	}

	Cat &operator=(const Cat &other) {
		std::cout << "Copy Cat assignment operator called" << std::endl;
		
		if (this != &other)
			type = other.type;
		return *this;
	}

	Cat(Cat &copy) {
		std::cout << "Copy Cat constructor called" << std::endl;

		*this = copy;
		type = copy.type;
	}

	void makeSound() {
		std::cout << "Cat just barked" << std::endl;
	}

	std::string getType () {
		return (type);
	}

};

#endif
