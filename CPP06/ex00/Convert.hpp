/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:59:48 by ernda-si          #+#    #+#             */
/*   Updated: 2026/04/20 19:21:56 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <limits>

class ScalarConvert
{
private:
	
	ScalarConvert();
	~ScalarConvert();
	//recebe como cada valor requirido e converte para string logo apos
	static std::string to_string(unsigned char var)
	{
		if (!var)
			return ("impossible");
		return (std::string(1, var));
	};
	// static std::string to_string(int var);
	// static std::string to_string(float var);
	// static std::string to_string(double var);
	
	
public:

	static size_t	find_n_times(std::string str, char target)
	{
		size_t	occur = 0;
		int		i = -1;

		while (str[++i])
		{
			if (str[i] == target)
				occur++;
		}
		std::cout << target << ": " << occur << std::endl;
		return occur;
	}

	
	static bool is_number(const std::string &var)
	{
		if (var.empty() || find_n_times(var, '-') > 1 
			|| find_n_times(var, '.') > 1 || find_n_times(var, 'f') > 1 
				|| var.find_first_not_of("1234567890-.f") != std::string::npos 
					|| (var.find('.') != std::string::npos && !isdigit(var[var.find('.') + 1])) 
						|| (var.find('-') != std::string::npos && !isdigit(var[var.find('-') + 1])) 
							|| (var.find('f') != std::string::npos && var[var.find('f') + 1]))
			return false;
		std::cout << var << std::endl;
		return true;
	}

	static void convert(const std::string &var) {

		double	value = 0;
		if (is_number(var))
		{
			std::cout << var << " is a number" << std::endl;
			return ;
		}
		if (var == "nan" || var == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (var.size() == 1)
			value = static_cast<double>(var[0]);
		else if (var == "+inf" || var == "+inff")
			value = std::numeric_limits<double>::infinity();
		else if (var == "-inf" || var == "-inff")
			value = -std::numeric_limits<double>::infinity();
		else
		{
			std::cerr << "Not a number" << std::endl;
			return ;
		}
		std::cout << "char: " << to_string(static_cast<unsigned char>(value)) << std::endl;
	};
};

ScalarConvert::ScalarConvert()
{
}

ScalarConvert::~ScalarConvert()
{
}


#endif
