#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("No Name"), _hp(10), _ep(10), _atk(0) 
{
	std::cout << "ClapTrap " << BLUE << this->_name << RESET << " has been created!" << std::endl;
};
ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _atk(0)
{
	std::cout << "ClapTrap " << BLUE << this->_name << RESET << " has been created!" << std::endl;
};
ClapTrap::ClapTrap(const ClapTrap &ref)
{
	*this = ref;
	std::cout << "ClapTrap " << BLUE << this->_name << RESET << " has been copied!" << std::endl;
};
ClapTrap::~ClapTrap() {std::cout << "ClapTrap " << BLUE << this->_name << RED << " has been destroyed!" << RESET <<std::endl;};

std::string ClapTrap::GetName() const {return this->_name;};
unsigned int ClapTrap::GetHp() const {return this->_hp;};
unsigned int ClapTrap::GetEp() const {return this->_ep;};
unsigned int ClapTrap::GetAtk() const {return this->_atk;};

void ClapTrap::SetName(std::string name) {this->_name = name;};
void ClapTrap::SetHp(unsigned int hp) {this->_hp = hp;};
void ClapTrap::SetEp(unsigned int ep) {this->_ep = ep;};
void ClapTrap::SetAtk(unsigned int atk) {this->_atk = atk;};

ClapTrap &ClapTrap::operator=(const ClapTrap &ref)
{
	this->_name = ref.GetName();
	this->_hp = ref.GetHp();
	this->_ep = ref.GetEp();
	this->_atk = ref.GetAtk();
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_ep <= 0)
	{
		std::cout << "ClapTrap " << BLUE << this->_name << RESET 
				  << " has no more energy points to attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << BLUE << this->_name << RESET 
			  << " attacks " << RED << target << RESET 
			  << ", causing " << RED << this->_atk << RESET 
			  << " points of damage!" << std::endl;
	this->_ep -= 1;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << BLUE << this->_name << RESET << " is already dead!" << std::endl;
		return ;
	}
	this->_hp -= amount;
	std::cout << BLUE << this->_name << RESET 
			  << " takes " << RED << amount << RESET 
			  << " points of damage!" << "(" << this->_hp
			  << " HP remaining" << ")"<< std::endl;
	if (this->_hp <= amount)
	{
		this->_hp = 0;
		std::cout << BLUE << this->_name << RESET << " died!" << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_hp += amount;
	std::cout << BLUE << this->_name << RESET << " is repaired of " 
			  << GREEN << amount << " HP " << RESET << "(" 
			  << this->_hp << " HP remaining" << ")"<< std::endl;
}