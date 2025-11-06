/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:53:35 by ernda-si          #+#    #+#             */
/*   Updated: 2025/11/03 15:59:38 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

# include <iostream>

class ClapTrap
{

private:

	std::string	_name;
	int 		_hitPoints;
	int 		_energyPoints;
	int 		_attackDamage;

public:

	ClapTrap(std::string name) {
		std::cout << "Constructor called" << std::endl;
		_name = name;
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

	ClapTrap &operator=(const ClapTrap &other);

	ClapTrap(ClapTrap &copy);

	void attack(const std::string& target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);

};

#endif