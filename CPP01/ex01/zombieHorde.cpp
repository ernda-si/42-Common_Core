/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:26 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/15 14:18:46 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie  *zombie;
    int     i;

    i = -1;
    if (N <= 0)
    {
        std::cout << "N must be greater than 0" << std::endl;
        return NULL;
    }
    zombie = new Zombie[N];
    while (++i < N)
        zombie[i].set_name(name);
    return (zombie);
}
