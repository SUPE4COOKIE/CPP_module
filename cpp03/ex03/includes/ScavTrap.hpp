#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"
class ScavTrap : virtual public ClapTrap
{
private:
	bool _is_guarding;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &);
	void guardGate();
	void highFivesGuys(void);
	void attack(const std::string& target);
};

#endif