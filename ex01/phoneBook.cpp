#include "phoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Constructor of phoneBook" << std::endl;
	contactCount = 0;
	oldestContact = 0;
}
PhoneBook::~PhoneBook() { std::cout << "Destructor  of phoneBook" << std::endl; }

std::string removeSpaces(const std::string& str)
{
	std::string result;
	bool	allSpaces = false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isspace(str[i]) || allSpaces)
		{
			result += str[i];
			allSpaces = true;
		}
	}
	return (result);
}

Contact newContactFill()
{
	Contact contactFill;
	std::string input;
	bool isAllDigit = true;
	size_t i = 0;
	do
	{
		std::cout << "First name: ";
		std::getline(std::cin, input);
		input = removeSpaces(input);
	} while (input.empty());
	contactFill.setFirstName(input);
	input.clear();
	do
	{
		std::cout << "Last name: ";
		std::getline(std::cin, input);
		input = removeSpaces(input);
	} while (input.empty());
	contactFill.setLastName(input);
	input.clear();
	do
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		input = removeSpaces(input);
	} while (input.empty());
	contactFill.setNickname(input);
	input.clear();
	do
	{
		std::cout << "PhoneNumber: ";
		std::getline(std::cin, input);
		while (i < input.length() && isAllDigit)
		{
			if (!isdigit(input[i]))
				isAllDigit = false;
			i++;
		}
		if (!input.empty() && isAllDigit)
			break;
		std::cout << "Invalid phone number! Only digits allowed." << std::endl;
	} while (input.empty() || !isAllDigit);
	contactFill.setPhoneNumber(input);
	input.clear();
	do
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, input);
		input = removeSpaces(input);
	} while (input.empty());
	contactFill.setDarkestSecret(input);
	return (contactFill);
}

void PhoneBook::addContact()
{
	Contact newContact;

	newContact = newContactFill();
	if (contactCount < 8)
	{
		contacts[contactCount] = newContact;
		contactCount++;
	}
	else
	{
		contacts[oldestContact] = newContact;
		oldestContact = (oldestContact + 1) % 8;
	}
}

void PhoneBook::searchContact(int index) const
{
	if (index >= 0 && index < contactCount)
	{
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "DarkestSecret: " << contacts[index].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "Contact not found." << std::endl;
}

void PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactCount; ++i)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << truncateString(contacts[i].getLastName()) << "|"
				  << std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
	}
}

std::string PhoneBook::truncateString(const std::string &str) const
{
	if (str.length() > 10)
	{
		return str.substr(0, 9) + ".";
	}
	return str;
}