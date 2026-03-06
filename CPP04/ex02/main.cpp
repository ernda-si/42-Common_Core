/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:42:13 by ernda-si          #+#    #+#             */
/*   Updated: 2026/03/06 17:27:21 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n=== Testing sounds and types ===" << std::endl;
	std::cout << j->getType() << ": " << std::endl;
	j->makeSound();
	std::cout << i->getType() << ": " << std::endl;
	i->makeSound();


	std::cout << "\n=== Deleting all animals ===" << std::endl;
	delete j;
	delete i;

	return 0;
}
