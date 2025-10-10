/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:50:39 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 15:50:41 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *z1 = NULL;
	Zombie *z2 = NULL;

	z1 = z1->newZombie("Carlos");
	z1->announce();
	delete z1;
	z2->randomChump("Andre");
}
