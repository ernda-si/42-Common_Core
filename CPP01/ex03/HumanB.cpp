/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 23:10:42 by eve               #+#    #+#             */
/*   Updated: 2025/09/12 23:11:24 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &w_type) {
    weapon = &w_type;
}

void HumanB::attack() const {
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
