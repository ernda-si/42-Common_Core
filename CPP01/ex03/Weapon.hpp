/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:34:03 by eve               #+#    #+#             */
/*   Updated: 2025/09/12 23:12:34 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {

    private:

    std::string type;

    public:

    Weapon(std::string w_type) {
        setType(w_type);
    }

    ~Weapon() {}

    const std::string &getType() const;

    void setType(std::string name);

};

#endif
