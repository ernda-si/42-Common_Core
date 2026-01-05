/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:11:22 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/04 23:09:03 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " has died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
	_hitPoints += amount;
	_energyPoints -= 1;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "Copy constructor called" << std::endl;
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