/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:37:49 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/15 15:27:55 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {

	private:

	std::string _name;

	public:

	Zombie(std::string n) {
		_name = n;
	}

	~Zombie() {
		std::cout << "Zombie " << _name << " was destroyed!" << std::endl;
	}

	Zombie* newZombie(std::string name);

	void    randomChump(std::string name);

	void    announce(void) const;

};

#endif