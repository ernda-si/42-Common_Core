/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:59:48 by ernda-si          #+#    #+#             */
/*   Updated: 2026/04/21 19:00:41 by ernda-si         ###   ########.fr       */
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

	static std::string to_string(unsigned char value)
	{
		if (!value)
			return ("impossible");
		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << std::endl;
		return (std::string(1, value));
	};

	static std::string to_string(int value)
	{
		if (!value)
			return ("impossible");
		std::cout << "char: " << static_cast<char>(value) << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << std::endl;
		return (std::string(1, value));
	};

	static std::string to_string(double value)
	{
		if (!value)
			return ("impossible");
		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "char: " << static_cast<char>(value) << std::endl;
		std::cout << "float: " << static_cast<float>(value) << std::endl;
		return (std::string(1, value));
	};

	static std::string to_string(float value)
	{
		if (!value)
			return ("impossible");
		std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
		std::cout << "char: " << static_cast<char>(value) << std::endl;
		return (std::string(1, value));
	};

public:

	static size_t	countChars(std::string str, char target)
	{
		size_t	occur = 0;
		int		i = -1;

		while (str[++i])
		{
			if (str[i] == target)
				occur++;
		}
		return occur;
	}

	static bool is_number(const std::string &var)
	{
		if (var.empty() || countChars(var, '-') > 1 || countChars(var, '.') > 1 || countChars(var, 'f') > 1 
				|| var.find_first_not_of("1234567890-.f") != std::string::npos 
					|| (var.find('.') != std::string::npos && !isdigit(var[var.find('.') + 1])) 
						|| (var.find('-') != std::string::npos && (!isdigit(var[var.find('-') + 1]) || var.find('-') != 0)) 
							|| (var.find('f') != std::string::npos && var[var.find('f') + 1]))
			return false;
		return true;
	}

	static void convert(const std::string &var) {

		double	value = 0;

		if (is_number(var))
			std::cout << var << " is a number" << std::endl;
		else if (var == "nan" || var == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (var.size() == 1)
			value = static_cast<double>(var[0]);
		else if (var == "+inf" || var == "+inff")
			value = std::numeric_limits<double>::infinity();
		else if (var == "-inf" || var == "-inff")
			value = -std::numeric_limits<double>::infinity();
		else
			std::cerr << "Not a number" << std::endl;
		std::cout << to_string(static_cast<int>(value)) << std::endl;
	};
};

ScalarConvert::ScalarConvert()
{
}

ScalarConvert::~ScalarConvert()
{
}


#endif
