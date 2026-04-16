/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:59:13 by ernda-si          #+#    #+#             */
/*   Updated: 2026/04/16 16:21:20 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Must have exactly 1 argument!" << std::endl;
		return 1;
	}
	std::string arg = av[1];
	ScalarConvert::convert(arg);
}
