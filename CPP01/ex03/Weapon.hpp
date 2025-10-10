/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:39:09 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 16:39:10 by ernda-si         ###   ########.fr       */
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
