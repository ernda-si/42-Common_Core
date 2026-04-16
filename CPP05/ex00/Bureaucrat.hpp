/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:38:18 by ernda-si          #+#    #+#             */
/*   Updated: 2026/04/10 18:56:53 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {

private:
	
	
	std::string	name;
	int					grade;
	
public:

	Bureaucrat(std::string n, int g)
	{
		name = n;
		grade = g;
	}
	std::string	getName() {return name;};
	int         getGrade() {return grade;};
	void		increaseGrade() {grade--;};
	void		DecreaseGrade() {grade++;};
	Bureaucrat	GradeTooHighException() {
		
	};
	// std::ostream &operator<<() {};
	

};

#endif