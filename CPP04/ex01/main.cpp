/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:42:13 by ernda-si          #+#    #+#             */
/*   Updated: 2026/03/06 17:27:43 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int	n = 4;
	Animal*	animals[n];

	for (int i = 0; i < n / 2; i++)
		animals[i] = new Dog();
	for (int i = n / 2; i < n; i++)
		animals[i] = new Cat();

	std::cout << "\n=== Testing sounds and types ===" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << animals[i]->getType() << ": " << std::endl;
		animals[i]->makeSound();
	}

	std::cout << "\n=== Testing deep copy ===" << std::endl;
	Dog*	original = new Dog();
	Dog*	copy = new Dog(*original);

	delete original;
	copy->makeSound();
	delete copy;

	std::cout << "\n=== Deleting all animals ===" << std::endl;
	for (int i = 0; i < n; i++)
		delete animals[i];

	return 0;
}
