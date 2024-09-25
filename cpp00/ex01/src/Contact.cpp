#include "Contact.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

int Contact::SetData()
{
	std::cout << "Type your First Name: ";
	std::getline(std::cin, this->FirstName);
	std::cout << "Type your Last Name: ";
	std::getline(std::cin, this->LastName);
	std::cout << "Type your Nick Name: ";
	std::getline(std::cin, this->NickName);
	std::cout << "Type your Phone Number: ";
	std::getline(std::cin, this->PhoneNumber);
	std::cout << "Type your Darkest secret: ";
	std::getline(std::cin, this->DarkestSecret);
	return (0);
}