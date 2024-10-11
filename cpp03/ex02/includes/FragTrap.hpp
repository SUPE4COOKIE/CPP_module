#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	/* data */
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &);
	~FragTrap();
	void highFivesGuys(void);
	void attack(const std::string& target);
};

#endif