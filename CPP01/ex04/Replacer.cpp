/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:39:25 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/10 17:19:59 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

FileReplacer::FileReplacer(char **av)
{
	filename = av[1];
	newfile = av[1];
	newfile += ".replace";
	s1 = av[2];
	s2 = av[3];
}

void FileReplacer::replace() {
	std::string line;

	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cerr << "Failed to open infile" << std::endl;
		return;
	}
	std::ofstream outfile(newfile.c_str());
	if(!outfile) {
		std::cerr << "Failed to open outfile" << std::endl;
		return;
	}
	if (s1.size() == 0)
		return ;
	while (std::getline(infile, line)) {
		size_t start = 0;
		size_t pos;
		while ((pos = line.find(s1, start)) != std::string::npos) {
			outfile << line.substr(start, pos - start);
			outfile << s2;
			start = pos + s1.length();
		}
		outfile << line.substr(start) << std::endl;
	}
	infile.close();
	outfile.close();
}
