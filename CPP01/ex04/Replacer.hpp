/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:50:14 by eve               #+#    #+#             */
/*   Updated: 2025/09/30 17:38:47 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

# include <iostream>
# include <fstream>

class FileReplacer {

private:

	std::string	filename;
	std::string	newfile;
	std::string	s1;
	std::string	s2;

public:

	FileReplacer(char **av);

	~FileReplacer() {};

	void	replace();

};

#endif
