/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:03:44 by ernda-si          #+#    #+#             */
/*   Updated: 2026/03/03 12:54:57 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	ClapTrap ct1("CT-01");
	ct1.attack("target");
	ct1.takeDamage(5);
	ct1.beRepaired(3);

	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	ScavTrap st1("ST-01");
	st1.attack("enemy");
	st1.takeDamage(30);
	st1.beRepaired(20);
	st1.guardGate();

	std::cout << "\n=== Testing ScavTrap Copy ===" << std::endl;
	ScavTrap st2(st1);
	st2.attack("another enemy");

	std::cout << "\n=== Destructors ===" << std::endl;
	return (0);
}