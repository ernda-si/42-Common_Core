/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:53:35 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/31 17:01:56 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

# include <iostream>

class ClapTrap
{

private:

	std::string	_Name;
	int 		_hitPoints;
	int 		_energyPoints;
	int 		_attackDamage;

public:

	ClapTrap(std::string name) {
		std::cout << "Constructor called" << std::endl;
		_Name = name;
		_hitPoints = 10;
		_energyPoints = 10;
		_attackDamage = 0;
	}

	ClapTrap() {
		std::cout << "Default constructor called" << std::endl;
	}

	~ClapTrap() {
		std::cout << "Default destructor called" << std::endl;
	}

	void attack(const std::string& target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);

};

#endif