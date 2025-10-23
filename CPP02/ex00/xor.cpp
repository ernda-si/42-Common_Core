/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:20:40 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/23 20:13:43 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
#include <iostream>

/* void encrypt() {
	std::string line;
	char        *new_line;
	char        xorKey = 'k';
	int         i = 0;

	std::ifstream infile("xor.cpp");
	if (!infile) {
		std::cerr << "Failed to open infile" << std::endl;
		return;
	}
	std::ofstream outfile("xor.encrypted");
	if(!outfile) {
		std::cerr << "Failed to open outfile" << std::endl;
		return;
	}
	while (std::getline(infile, line))
	{
		i = 0;
		while (line[i])
		{
			new_line[i] = line[i] ^ xorKey;
			i++;
		}
		outfile << new_line;
	}
	infile.close();
	outfile.close();
} 

void decrypt() {
	std::string line;
	char        *new_line;
	char        xorKey = 'k';
	int         i = 0;

	std::ifstream infile("xor.encrypted");
	if (!infile) {
		std::cerr << "Failed to open infile" << std::endl;
		return;
	}
	std::ofstream outfile("xor.recovered");
	if(!outfile) {
		std::cerr << "Failed to open outfile" << std::endl;
		return;
	}
	while (std::getline(infile, line))
	{
		i = 0;
		while (line[i])
		{
			// new_line[i] = line[i] ^ xorKey;
			new_line[i] = xorKey ^ line[i];
			i++;
		}
		outfile << new_line;
	}
	infile.close();
	outfile.close();
} 

int main(void)
{
	encrypt();
	decrypt();
} */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// bool xor_file_stream(const std::string &in_path, const std::string &out_path, unsigned char key) {
//     std::ifstream infile(in_path, std::ios::binary);
//     if (!infile) {
//         std::cerr << "Failed to open input file: " << in_path << '\n';
//         return false;
//     }

//     std::ofstream outfile(out_path, std::ios::binary);
//     if (!outfile) {
//         std::cerr << "Failed to open output file: " << out_path << '\n';
//         return false;
//     }

//     const std::size_t BUFSIZE = 64 * 1024;
//     std::vector<char> buf(BUFSIZE);

//     while (infile) {
//         infile.read(buf.data(), static_cast<std::streamsize>(buf.size()));
//         std::streamsize n = infile.gcount();
//         if (n <= 0) break;
//         for (std::streamsize i = 0; i < n; ++i) {
//             buf[i] = static_cast<char>(static_cast<unsigned char>(buf[i]) ^ key);
//         }
//         outfile.write(buf.data(), n);
//     }

//     return true;
// }

// int main(int argc, char **argv) {
//     if (argc != 4) {
//         std::cerr << "Usage: " << argv[0] << " <infile> <outfile> <key-char>\n";
//         return 1;
//     }
//     std::string in = argv[1];
//     std::string out = argv[2];
//     unsigned char key = static_cast<unsigned char>(argv[3][0]);

//     if (!xor_file_stream(in, out, key)) return 1;
//     std::cout << "Done: " << in << " -> " << out << " (key='" << argv[3][0] << "')\n";
//     return 0;
// }


// xor_tool.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool xor_file_stream(const std::string &in_path,
                     const std::string &out_path,
                     const std::string &key) {
    if (key.empty()) {
        std::cerr << "Key must not be empty\n";
        return false;
    }

    std::ifstream infile(in_path, std::ios::binary);
    if (!infile) {
        std::cerr << "Failed to open input file: " << in_path << '\n';
        return false;
    }

    std::ofstream outfile(out_path, std::ios::binary | std::ios::trunc);
    if (!outfile) {
        std::cerr << "Failed to open output file: " << out_path << '\n';
        return false;
    }

    const std::size_t BUFSIZE = 64 * 1024; // 64 KB
    std::vector<char> buf(BUFSIZE);
    std::size_t key_len = key.size();
    std::size_t key_pos = 0; // persist across chunks

    while (infile) {
        infile.read(buf.data(), static_cast<std::streamsize>(buf.size()));
        std::streamsize n = infile.gcount();
        if (n <= 0) break;

        for (std::streamsize i = 0; i < n; ++i) {
            buf[i] = static_cast<char>( static_cast<unsigned char>(buf[i])
                                        ^ static_cast<unsigned char>(key[key_pos]) );
            key_pos = (key_pos + 1) % key_len;
        }

        outfile.write(buf.data(), n);
        if (!outfile) {
            std::cerr << "Write error\n";
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <infile> <outfile> <key-string>\n";
        return 1;
    }
    std::string infile = argv[1];
    std::string outfile = argv[2];
    std::string key = argv[3];

    if (!xor_file_stream(infile, outfile, key)) {
        std::cerr << "Operation failed\n";
        return 1;
    }
    std::cout << "Done: " << infile << " -> " << outfile << " (key len=" << key.size() << ")\n";
    return 0;
}

/* void encrypt() {
	std::string line;
	char        *new_line;
	char        xorKey[] = "chave123";
	int         i = 0;
	int         j = 0;

	std::ifstream infile("xor.cpp");
	if (!infile) {
		std::cerr << "Failed to open infile" << std::endl;
		return;
	}
	std::ofstream outfile("xor.encrypted");
	if(!outfile) {
		std::cerr << "Failed to open outfile" << std::endl;
		return;
	}
	while (std::getline(infile, line))
	{
		i = 0;
		while (line[i])
		{
			j = 0;
			while (xorKey[j])
			{
				new_line[i] = line[i] ^ xorKey[j];
				j++;
			}
			i++;
		}
		outfile << new_line;
	}
	infile.close();
	outfile.close();
} */