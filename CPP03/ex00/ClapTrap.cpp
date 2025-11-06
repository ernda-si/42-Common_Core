/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:11:22 by ernda-si          #+#    #+#             */
/*   Updated: 2025/11/03 16:02:27 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints > 0) {
		std::cout << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else
		std::cout << "Not enough energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		std::cout << _name << " has been attacked and lost " << amount << " of hit points!" << std::endl;
		_hitPoints -= amount;
	}
	else
		std::cout << "No hit points left for " << _name << " to lose!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0) {		
		std::cout << _name << " repaired " << amount << " hit points " << std::endl;
		_energyPoints -= 1;
	}
	else
		std::cout << "Not enough energy points left!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy) {
	std::cout << "Copy constructor called!" << std::endl;

	*this = copy;
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Copy assignment operator called!" << std::endl;

	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}