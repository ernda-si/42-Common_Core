/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:53:35 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/04 23:19:58 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

# include <iostream>

class ClapTrap
{

protected:

	std::string	_name;
	int 		_hitPoints;
	int 		_energyPoints;
	int 		_attackDamage;

public:

	ClapTrap(std::string name) {
		std::cout << "ClapTrap constructor called" << std::endl;
		_name = name;
		_hitPoints = 10;
		_energyPoints = 10;
		_attackDamage = 0;
	}

	ClapTrap() {
		std::cout << "ClapTrap default constructor called" << std::endl;
	}

	~ClapTrap() {
		std::cout << "ClapTrap destructor called" << std::endl;
	}

	ClapTrap &operator=(const ClapTrap &other);

	ClapTrap(const ClapTrap &copy);

	void attack(const std::string& target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);

};

#endif
