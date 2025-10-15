/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:21 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/15 15:27:30 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Zombie {

	private:

	std::string _name;

	public:

	Zombie() {}

	Zombie(std::string n) {
		_name = n;
	}

	~Zombie() {
		std::cout << "Zombie " << _name << " has been destroyed!" << std::endl;
	}

	void    announce(void) const;
	void	set_name(std::string n);

};

Zombie* zombieHorde(int N, std::string name);

#endif
