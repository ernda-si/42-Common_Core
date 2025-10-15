/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:49 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/15 15:26:57 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &w_type) {
    _Weapon = &w_type;
}

void HumanB::attack() const {
    std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
}
