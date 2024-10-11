#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
	std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " has been created!" << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " has been created!" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &ref)
{
	*this = ref;
	std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " has been copied!" << std::endl;
};

ScavTrap::~ScavTrap() {std::cout << "ScavTrap " << BLUE << this->GetName() << RED << " has been destroyed!" << RESET <<std::endl;};

void ScavTrap::guardGate()
{
	if (this->GetHp() <= 0)
	{
		std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " is dead and can't guard the Gate!" << std::endl;
		return ;
	}
	if (this->_is_guarding)
	{
		std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " is already guarding the gate!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " is now in gate keeper mode!" << std::endl;
	this->_is_guarding = true;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->GetEp() <= 0)
	{
		std::cout << "ScavTrap " << BLUE << this->GetName() << RESET 
				  << " has no more energy points to attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << BLUE << this->GetName() << RESET 
			  << " attacks " << RED << target << RESET 
			  << ", causing " << RED << this->GetAtk() << RESET 
			  << " points of damage!" << std::endl;
	this->SetEp(this->GetEp() - 1);
}