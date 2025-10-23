/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:25:28 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/23 19:15:51 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <filesystem>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct s_file {
	
	char			*content;

	std::fstream	fin, fout;

}	t_file;

typedef struct s_tree {

	char	*path;
	t_tree	dir;
	t_file	*file;

}	t_tree;

int main(int argc, char **argv)
{
	DIR				*FD;
	struct dirent	*in_file;
	char			*target_dir = getcwd(NULL, 0);

	// return (printf("target_dir: %s\n", target_dir));
	/* Scanning the target directory */
	FD = opendir("/home");
	if (FD == NULL)
	{
		fprintf(stderr, "Error: Failed to open input directory - %s\n", \
			strerror(errno));
		return 1;
	}

	/* Reading object (files, directories ...) from the folder */
	while ((in_file = readdir(FD)))
	{
		struct stat buffer;
		int         status;

		status = stat(in_file->d_name, &buffer);

		/* check status */
		// if (status == -1)
		// 	return (fprintf(stderr, "Error: Failed to stat item - %s\n", \
		// 		strerror(errno)), 1);

		/* check result */
		if ( buffer.st_mode & S_IFREG )
			printf("%s is file \n", in_file->d_name);
		else
			printf("%s is dir\n", in_file->d_name);
	}
	closedir(FD);

	return 0;
}
