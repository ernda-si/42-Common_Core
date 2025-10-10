/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:38 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 16:38:40 by ernda-si         ###   ########.fr       */
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
