/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:38 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/15 15:27:09 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string nm, Weapon &w_type) {
    _name = nm;
    _Weapon = &w_type;
}

void HumanA::attack() const {
    std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
}
