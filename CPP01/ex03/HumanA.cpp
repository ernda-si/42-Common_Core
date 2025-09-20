/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 23:01:19 by eve               #+#    #+#             */
/*   Updated: 2025/09/12 23:10:04 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string nm, Weapon &w_type) {
    name = nm;
    weapon = &w_type;
}

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
