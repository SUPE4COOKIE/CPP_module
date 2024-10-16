#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("No name")
{
	std::cout << "DiamondTrap " << BLUE << this->GetName() << RESET << " has been created!" << std::endl;
	this->SetHp(this->FragTrap::GetHp());
	this->SetEp(this->ScavTrap::GetEp());
	this->SetAtk(this->FragTrap::GetAtk());
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap " << BLUE << this->_name << RESET << " has been created!" << std::endl;
	this->SetHp(this->FragTrap::GetHp());
	this->SetEp(this->ScavTrap::GetEp());
	this->SetAtk(this->FragTrap::GetAtk());
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref.GetName()), ScavTrap(ref._name), FragTrap(ref._name)
{
	*this = ref;
	std::cout << "DiamondTrap " << BLUE << this->GetName() << RESET << " has been copied!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ref)
{
	this->_name = ref._name;
	this->ClapTrap::SetName(ref.GetName());
	this->SetHp(ref.GetHp());
	this->SetEp(ref.GetEp());
	this->SetAtk(ref.GetAtk());
	return (*this);
}

DiamondTrap::~DiamondTrap() {}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << BLUE << this->_name
	<< RESET << " and my ClapTrap name is " << GREEN
	<< this->ScavTrap::GetName() << RESET << std::endl;
}