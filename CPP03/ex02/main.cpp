/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:03:44 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/04 23:19:58 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	FragTrap ft1("FT-01");
	ft1.attack("monster");
	ft1.takeDamage(50);
	ft1.beRepaired(25);
	ft1.highFivesGuys();

	std::cout << "\n=== Testing FragTrap Copy ===" << std::endl;
	FragTrap ft2(ft1);
	ft2.attack("another monster");
	ft2.highFivesGuys();

	std::cout << "\n=== Destructors ===" << std::endl;
	return 0;
}
