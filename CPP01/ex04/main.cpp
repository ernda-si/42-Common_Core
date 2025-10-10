/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:39:13 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 16:39:14 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int ac, char *av[])
{
	if (ac != 4) {
		std::cerr << "4 arguments are required" << std::endl;
		return (0);
	}
	FileReplacer	replace(av);
	replace.replace();
	return (1);
}
