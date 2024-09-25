#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include "Contact.hpp"
# define CONTACT_NBR 8

class PhoneBook
{
private:
	Contact Contacts[CONTACT_NBR];
	size_t NextContact;
public:
	PhoneBook(/* args */);
	~PhoneBook();
	void Add(void);
	void Search();
	void Exit();

};

#endif