/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:51:42 by eve               #+#    #+#             */
/*   Updated: 2025/09/12 23:11:10 by eve              ###   ########.fr       */
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
