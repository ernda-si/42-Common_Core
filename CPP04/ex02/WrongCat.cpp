/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:27:30 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/18 16:18:53 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	type = "wrong cat";
}

WrongCat::~WrongCat() {
	std::cout << "Default WrongCat destructor called" << std::endl;
}
