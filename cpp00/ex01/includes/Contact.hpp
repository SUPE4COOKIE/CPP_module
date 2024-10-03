#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <string>
#include <iostream>
class Contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
	bool GetInput(std::string message, std::string *value);
	
public:
	Contact(/* args */);
	~Contact();
	int SetData();
	std::string	GetFirstName();
	std::string	GetLastName();
	std::string	GetNickName();
	std::string	GetPhoneNumber();
	std::string	GetDarkestSecret();
	bool isEmpty();
};
#endif