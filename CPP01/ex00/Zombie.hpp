/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:25:19 by eve               #+#    #+#             */
/*   Updated: 2025/09/19 22:06:24 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {

	private:

	std::string name;

	public:

	Zombie(std::string n) {
		name = n;
	}

	~Zombie() {
		std::cout << "Zombie " << name << " was destroyed!" << std::endl;
	}

	Zombie* newZombie(std::string name);

	void    randomChump(std::string name);

	void    announce(void) const;

};

#endif