/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:44 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/15 15:27:02 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
    
    private:

    Weapon      *_Weapon;
    std::string _name;

    public:

    HumanA(std::string nm, Weapon &w_type);

    ~HumanA() {}

    void attack() const;
    
};

#endif
