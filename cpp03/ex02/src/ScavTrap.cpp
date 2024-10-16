#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _is_guarding(false)
{
	std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " has been created!" << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _is_guarding(false)
{
	std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " has been created!" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref.GetName())
{
	*this = ref;
	std::cout << "ScavTrap " << BLUE << this->GetName() << RESET << " has been copied!" << std::endl;
};

ScavTrap &ScavTrap::operator=(const ScavTrap &ref)
{
	this->SetName(ref.GetName());
	this->SetHp(ref.GetHp());
	this->SetEp(ref.GetEp());
	this->SetAtk(ref.GetAtk());
	this->_is_guarding = ref._is_guarding;
	return (*this);
}

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