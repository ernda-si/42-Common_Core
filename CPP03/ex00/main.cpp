/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:53:24 by ernda-si          #+#    #+#             */
/*   Updated: 2025/11/03 16:02:47 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    ct("Eve");
    ClapTrap    ct2 = ct;
    ClapTrap    ct3(ct2);

    ct.attack("Adam");
    ct2.beRepaired(50);
    ct3.takeDamage(10);

    return (1);
}
