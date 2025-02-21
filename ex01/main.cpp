# include <iostream>

#include "phoneBook.hpp"

int main() {
	PhoneBook	phonebook;
	std::string	command;
	int			index;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH") {
			phonebook.displayContacts();
			while (true)
			{
				std::cout << "Enter the index of the contact to view: ";
				std::string input;
				std::getline(std::cin, input);
				if (input.empty() || input.find_first_not_of("012345678") != std::string::npos)
					std::cout << "Invalid index!" << std::endl; 
				else
				{
					index = std::stoi(input);
					phonebook.searchContact(index);
					break ;
				}
			}
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}