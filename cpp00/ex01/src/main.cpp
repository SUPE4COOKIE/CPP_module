#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	book;
	std::string	cmd;

	std::cout << "Use ADD to add a new contact\nUse SEARCH to search for a user\nUse QUIT to quit the PhoneBook\n" << std::endl;
	while (true)
	{
		std::cout << "Enter a command: ";
		std::cin >> cmd;
		if (cmd == "ADD")
			book.Add();
		else if (cmd == "SEARCH")
			book.Search();
		else if (cmd == "QUIT")
		{
			book.Exit();
			break;
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
}