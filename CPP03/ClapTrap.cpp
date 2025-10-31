/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:11:22 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/31 16:58:57 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints > 0) {
		std::cout << _Name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else
		std::cout << "Not enough energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		std::cout << _Name << " has been attacked and lost " << amount << " of hit points!" << std::endl;
		_hitPoints -= amount;
	}
	else
		std::cout << "No hit points left for " << _Name << " to lose!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0) {		
		std::cout << _Name << " repaired " << amount << " hit points " << std::endl;
		_energyPoints -= 1;
	}
	else
		std::cout << "Not enough energy points left!" << std::endl;
}
