#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap dt("DiamondTrap");
	DiamondTrap dt2(dt);
	DiamondTrap dt3;

	dt.attack("target");
	std::cout << "HP: " << dt.GetHp() << std::endl;
	dt.takeDamage(10);
	std::cout << "HP: " << dt.GetHp() << std::endl;
	dt.beRepaired(10);
	std::cout << "HP: " << dt.GetHp() << std::endl;
	dt.guardGate();
	dt.guardGate();
	dt.highFivesGuys();
	dt.whoAmI();
	dt2.whoAmI();
	dt3.whoAmI();
	return (0);
}