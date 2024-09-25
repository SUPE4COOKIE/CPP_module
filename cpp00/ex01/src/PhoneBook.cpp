#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::Add()
{
	if (this->NextContact == CONTACT_NBR)
		this->NextContact = 0;
	this->Contacts[this->NextContact].SetData();
}

void PhoneBook::Search()
{

}

void PhoneBook::Exit()
{

}

