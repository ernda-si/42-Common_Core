/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 23:21:38 by eve               #+#    #+#             */
/*   Updated: 2025/09/12 17:44:16 by eve              ###   ########.fr       */
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
        exit(1);
    }
    zombie = new Zombie[N];
    while (++i < N)
        zombie[i].set_name(name);
    return (zombie);
}
