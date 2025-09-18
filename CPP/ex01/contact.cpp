/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:17:34 by ernda-si          #+#    #+#             */
/*   Updated: 2025/09/18 13:18:12 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	Contact::print_info(void) const {
	print_format(first_name);
	print_format(last_name);
	print_format(nickname);
	std::cout << std::endl;
	return (1);
}
