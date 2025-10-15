/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:39:30 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/15 15:22:38 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

# include <iostream>
# include <fstream>

class FileReplacer {

private:

	std::string	_fileName;
	std::string	_newFile;
	std::string	_s1;
	std::string	_s2;

public:

	FileReplacer(char **av);

	~FileReplacer() {};

	void	replace();

};

#endif
