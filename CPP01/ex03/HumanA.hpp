/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:50:31 by eve               #+#    #+#             */
/*   Updated: 2025/09/12 23:09:53 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
    
    private:

    Weapon      *weapon;
    std::string name;

    public:

    HumanA(std::string nm, Weapon &w_type);

    ~HumanA() {}

    void attack() const;
    
};

#endif
