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
		getline(std::cin, cmd);
		if (std::cin.eof())
			return 0;
		if (cmd == "ADD")
		{
			if (book.Add())
				return 0;
		}
		else if (cmd == "SEARCH")
			book.Search();
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	book.Exit();
}