#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), _name("No Name")
{
	std::cout << "DiamondTrap " << BLUE << this->GetName() << RESET << " has been created!" << std::endl;
	this->SetHp(100);
	this->SetEp(50);
	this->SetAtk(30);
}