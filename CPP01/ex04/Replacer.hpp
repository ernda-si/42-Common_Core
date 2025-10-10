/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:39:30 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 16:39:31 by ernda-si         ###   ########.fr       */
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
