/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:53 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 16:38:54 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
    
    private:

    Weapon      *weapon;
    std::string name;

    public:

    HumanB(std::string nm) {
        name = nm;
    }
    
    ~HumanB() {}

    void attack() const;

    void setWeapon(Weapon &w_type);
    
};

#endif
