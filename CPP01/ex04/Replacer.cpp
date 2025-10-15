/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:39:25 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/15 15:25:36 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

FileReplacer::FileReplacer(char **av)
{
	_fileName = av[1];
	_newFile = av[1];
	_newFile += ".replace";
	_s1 = av[2];
	_s2 = av[3];
}

void FileReplacer::replace() {
	std::string line;

	std::ifstream infile(_fileName.c_str());
	if (!infile) {
		std::cerr << "Failed to open infile" << std::endl;
		return;
	}
	std::ofstream outfile(_newFile.c_str());
	if(!outfile) {
		std::cerr << "Failed to open outfile" << std::endl;
		return;
	}
	if (_s1.size() == 0)
		return ;
	while (std::getline(infile, line)) {
		size_t start = 0;
		size_t pos;
		while ((pos = line.find(_s1, start)) != std::string::npos) {
			outfile << line.substr(start, pos - start);
			outfile << _s2;
			start = pos + _s1.length();
		}
		outfile << line.substr(start) << std::endl;
	}
	infile.close();
	outfile.close();
}
