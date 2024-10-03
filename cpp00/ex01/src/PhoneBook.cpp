#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(/* args */)
{
	this->NextContact = 0;
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::Add()
{
	if (this->NextContact == CONTACT_NBR)
		this->NextContact = 0;
	if (this->Contacts[this->NextContact].SetData())
		return 1;
	this->NextContact++;
	return 0;
}

std::string PhoneBook::SearchFormat(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	else
	{
		str.insert(0, 10 - str.length(), ' ');
	}
	return (str);
}
int PhoneBook::SearchInput(std::string message)
{
	std::string tmp;
	int result;
	bool valid = false;

	do
	{
		std::cout << message;
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			return -1;
		if (tmp.empty())
		{
			std::cout << "Invalid Input" << std::endl;
			return -2;
		}
		for (size_t i = 0; i < tmp.length(); i++)
		{
			if (!isdigit(tmp[i]))
			{
				std::cout << "Invalid Input" << std::endl;
				return -2;
			}
		}
		std::stringstream sstream(tmp);
		sstream >> result;
		if (result < 0 || result >= CONTACT_NBR || this->Contacts[result].isEmpty())
		{
			std::cout << "Invalid Input" << std::endl;
			return -2;
		}
		else
			valid = true;
	} while (!valid);
	return result;
}

void PhoneBook::PrintContact(int index)
{
	std::cout << "First Name: " << this->Contacts[index].GetFirstName() << std::endl;
	std::cout << "Last Name: " << this->Contacts[index].GetLastName() << std::endl;
	std::cout << "Nick Name: " << this->Contacts[index].GetNickName() << std::endl;
	std::cout << "Phone Number: " << this->Contacts[index].GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->Contacts[index].GetDarkestSecret() << std::endl;
}
int PhoneBook::Search()
{
	std::string input;
	int index;
	std::cout << std::endl << "     index| first name| last name| Nick Name" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;

	for (size_t i = 0; i < CONTACT_NBR; i++)
	{
		if (this->Contacts[i].isEmpty())
			break;
		std::cout << "         " << i << "| ";
		std::cout << SearchFormat(this->Contacts[i].GetFirstName()) << "|";
		std::cout << SearchFormat(this->Contacts[i].GetLastName()) << "|";
		std::cout << SearchFormat(this->Contacts[i].GetNickName()) << std::endl;
	}
	index = this->SearchInput("Enter an ID: ");
	if (index < 0)
		return 1;
	PrintContact(index);
	return 0;
}

void PhoneBook::Exit()
{
	std::cout << "Exiting..." << std::endl;
}

