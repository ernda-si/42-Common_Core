/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:19:53 by ernda-si          #+#    #+#             */
/*   Updated: 2026/03/06 14:19:55 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Default Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Copy Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const {
	return (this->ideas[index]);
}

void Brain::setIdea(int index, const std::string &idea) {
	this->ideas[index] = idea;
}
