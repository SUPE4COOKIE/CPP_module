#include "Harl.hpp"

void Harl::debug(void) {std::cout << DEBUG_MSG << std::endl;}
void Harl::info(void) {std::cout << INFO_MSG << std::endl;}
void Harl::warning(void) {std::cout << WARNING_MSG << std::endl;}
void Harl::error(void) {std::cout << ERROR_MSG << std::endl;}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
			(this->*functions[i])();
	}
}

//cahnge Makefile

Harl::Harl()
{
}

Harl::~Harl()
{
}