/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:38:03 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/15 14:54:48 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string	arg = "test";
	int			N = 10;
	Zombie      *zh;

	zh = zombieHorde(N, arg);
	for (int i = 0; i < N; i++)
		zh[i].announce();
	delete[] zh;

	return 0;
}
