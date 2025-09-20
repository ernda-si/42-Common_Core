/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:25:17 by eve               #+#    #+#             */
/*   Updated: 2025/09/12 23:15:35 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::announce(void) const {
	std::cout << name << ":  BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string n) {
	name = n;
}
