#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &);
	DiamondTrap &operator=(const DiamondTrap &);
	~DiamondTrap();
	void whoAmI();
	std::string GetName() const;
	void SetName(std::string name);
	using ScavTrap::attack;
	using FragTrap::highFivesGuys;
	using ScavTrap::guardGate;
};

#endif