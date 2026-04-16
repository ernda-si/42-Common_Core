/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:59:48 by ernda-si          #+#    #+#             */
/*   Updated: 2026/04/16 19:18:58 by ernda-si         ###   ########.fr       */
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
	
	static bool is_number(const std::string &var)
	{
		int		i = 0;
		bool	dot_flag = false;
	
		if (!isdigit(var[0]))
			return false;
		while (var[i])
		{
			std::cout << "var: " << var[i] << std::endl;
			if (var[i] == '.')
			{
				if (dot_flag == true)
					return false;
				dot_flag = true;
				i++;
			}
			else if ((var[i] == 'f' && var[i + 1] != '\0') || (var[i] == '.' && !isdigit(var[i + 1])))
				return false;
			else if (!isalnum(var[i]) && (var[i] != 'f' || var[i] != '.'))
				return false;
			i++;
		}
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
