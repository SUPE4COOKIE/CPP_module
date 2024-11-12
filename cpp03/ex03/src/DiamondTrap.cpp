#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("No name_clap_name"), ScavTrap("No name_clap_name"), FragTrap("No name_clap_name"), _name("No name")
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

std::string DiamondTrap::GetName() const
{
	return (this->DiamondTrap::_name);
}

void DiamondTrap::SetName(std::string name)
{
	this->DiamondTrap::_name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref.GetName() + "_clap_name"), ScavTrap(ref.GetName()), FragTrap(ref.GetName())
{
	*this = ref;
	std::cout << "DiamondTrap " << BLUE << this->GetName() << RESET << " has been copied!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ref)
{
	this->DiamondTrap::SetName(ref.GetName());
	this->ClapTrap::SetName(ref.GetName() + "_clap_name");
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