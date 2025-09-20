/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:25:19 by eve               #+#    #+#             */
/*   Updated: 2025/09/12 23:15:20 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Zombie {

	private:

	std::string name;

	public:

	Zombie() {}

	Zombie(std::string n) {
		name = n;
	}

	~Zombie() {
		std::cout << "Zombie " << name << " has been destroyed!" << std::endl;
	}

	void    announce(void) const;
	void	set_name(std::string n);

};

Zombie* zombieHorde(int N, std::string name);

#endif
