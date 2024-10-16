#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() 
{
	this->SetHp(100);
	this->SetEp(100);
	this->SetAtk(30);
	std::cout << "FragTrap " << BLUE << this->GetName() << RESET << " has been created!" << std::endl;
};

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->SetHp(100);
	this->SetEp(100);
	this->SetAtk(30);
	std::cout << "FragTrap " << BLUE << this->GetName() << RESET << " has been created!" << std::endl;
};

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref.GetName())
{
	*this = ref;
	std::cout << "FragTrap " << BLUE << this->GetName() << RESET << " has been copied!" << std::endl;
};

FragTrap &FragTrap::operator=(const FragTrap &ref)
{
	this->SetName(ref.GetName());
	this->SetHp(ref.GetHp());
	this->SetEp(ref.GetEp());
	this->SetAtk(ref.GetAtk());
	return (*this);
}

FragTrap::~FragTrap() {std::cout << "FragTrap " << BLUE << this->GetName() << RED << " has been destroyed!" << RESET <<std::endl;};

void FragTrap::attack(const std::string& target)
{
	if (this->GetEp() <= 0)
	{
		std::cout << "FragTrap " << BLUE << this->GetName() << RESET 
				  << " has no more energy points to attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << BLUE << this->GetName() << RESET 
			  << " attacks " << RED << target << RESET 
			  << ", causing " << RED << this->GetAtk() << RESET 
			  << " points of damage!" << std::endl;
	this->SetEp(this->GetEp() - 1);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << BLUE << this->GetName() << RESET << " high fives guys!" << std::endl;
}