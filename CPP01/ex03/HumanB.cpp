/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:49 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 16:38:50 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &w_type) {
    weapon = &w_type;
}

void HumanB::attack() const {
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
