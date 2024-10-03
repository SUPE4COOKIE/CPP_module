#include "Contact.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

bool Contact::GetInput(std::string message, std::string *value)
{
	std::string tmp;
	bool valid = false;

	do
	{
		std::cout << message;
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			return false;
		else if (!tmp.empty())
			valid = true;
	} while (!valid);
	*value = tmp;
	return true;
}

std::string	Contact::GetFirstName()
{
	return (this->FirstName);
}

std::string	Contact::GetLastName()
{
	return (this->LastName);
}

std::string	Contact::GetNickName()
{
	return (this->NickName);
}

std::string	Contact::GetPhoneNumber()
{
	return (this->PhoneNumber);
}

std::string	Contact::GetDarkestSecret()
{
	return (this->DarkestSecret);
}

bool Contact::isEmpty()
{
	if (this->FirstName.empty())
		return (true);
	return (false);
}

int Contact::SetData()
{
	if (GetInput("Type your First Name: ", &this->FirstName) == false)
		return (1);
	if (GetInput("Type your Last Name: ", &this->LastName) == false)
		return (1);
	if (GetInput("Type your Nick Name: ", &this->NickName) == false)
		return (1);
	if (GetInput("Type your Phone Number: ", &this->PhoneNumber) == false)
		return (1);
	if (GetInput("Type your Darkest secret: ", &this->DarkestSecret) == false)
		return (1);
	return (0);
}