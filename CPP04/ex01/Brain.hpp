/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:47:04 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/03 21:30:29 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {

private:

	std::string ideas[100];

public:

	Brain();
	~Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &other);
	std::string getIdea(int index) const;
	void setIdea(int index, const std::string &idea);

};

#endif
