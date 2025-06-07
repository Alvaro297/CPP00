#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook
{
private:
	Contact contacts[8];
	int		contactCount;
	int		oldestContact;
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact(int index) const;
	void displayContacts() const;
	std::string truncateString(const std::string &str) const;
};

#endif