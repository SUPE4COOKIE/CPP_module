#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
private:
	bool _is_guarding;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &);
	~ScavTrap();
	void guardGate();
	void attack(const std::string& target);
};

#endif