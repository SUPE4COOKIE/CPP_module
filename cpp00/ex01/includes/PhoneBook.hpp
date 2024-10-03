#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include <sstream>
# include "Contact.hpp"
# define CONTACT_NBR 8

class PhoneBook
{
private:
	Contact Contacts[CONTACT_NBR];
	size_t NextContact;
	std::string SearchFormat(std::string str);
	int SearchInput(std::string message);
	void PrintContact(int index);
public:
	PhoneBook();
	~PhoneBook();
	int Add(void);
	int Search();
	void Exit();
};

#endif