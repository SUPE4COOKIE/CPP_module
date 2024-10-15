#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &);
	~FragTrap();
	FragTrap &operator=(const FragTrap &);
	void highFivesGuys(void);
	void attack(const std::string& target);
};

#endif