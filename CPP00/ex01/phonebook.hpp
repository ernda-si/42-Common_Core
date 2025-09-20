#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class	Contact {

private:

	std::string field_1;
	std::string	field_2;
	std::string	field_3;
	std::string	field_4;
	std::string	field_5;

public:

	void	add_f1(std::string name) {
		field_1 = name;
	}

	void	add_f2(std::string name) {
		field_2 = name;
	}

	void	add_f3(std::string name) {
		field_3 = name;
	}

	void	add_f4(std::string name) {
		field_3 = name;
	}

	void	add_f5(std::string name) {
		field_3 = name;
	}

	void	print_field(std::string field) const {
	if (field.size() >= 10)
		std::cout << field.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << std::right << field << "|";
	}

	void	print_all() {
		print_field(field_1);
		print_field(field_2);
		print_field(field_3);
		std::cout << std::endl;
	}

	bool	is_empty() {
		return (!field_1.empty());
	}

};

class	Phonebook {

private:

	Contact		contacts[8];
	int			index;

public:

	std::string	handle_input(std::string field) const {
		std::string	input;

		while (true) {
			std::cout << field << ": " << std::flush;
			getline(std::cin, input);
			if (!input.empty()) {
				return (input);
			}
		}
	}

	void	add_cmd() {
		if (Phonebook::index >= 8)
			Phonebook::index = 0;
		contacts[Phonebook::index].add_f1(handle_input("field_1"));
		contacts[Phonebook::index].add_f2(handle_input("field_2"));
		contacts[Phonebook::index].add_f3(handle_input("field_3"));
		contacts[Phonebook::index].add_f4(handle_input("field_4"));
		contacts[Phonebook::index].add_f5(handle_input("field_5"));
		Phonebook::index++;
	}

	void	search_cmd() {
		int	i;

		i = 0;
		std::cout << "     index|first name| last name|  nickname|" << std::endl;
		while (i < 8 && contacts[i].is_empty())
		{
			contacts[i].print_field(std::to_string(i));
			contacts[i].print_all();
			i++;
		}
	}

};

#endif
