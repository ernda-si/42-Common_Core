/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:17 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 16:38:18 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::announce(void) const {
	std::cout << name << ":  BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string n) {
	name = n;
}
