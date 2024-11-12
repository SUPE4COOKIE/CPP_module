#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("clap");
	ScavTrap scav("scav");
	ScavTrap copy(scav);

	scav.attack("copy");
	copy.takeDamage(20);
	std::cout << "copy hp: " << copy.GetHp() << std::endl;
	std::cout << "clap hp: " << clap.GetHp() << std::endl;
	copy.beRepaired(5);
	copy.takeDamage(20);
	std::cout << "copy hp: " << copy.GetHp() << std::endl;
	for (int i = 0; i < 11; i++)
	{
		scav.attack("copy");
		copy.takeDamage(scav.GetAtk());
	}
	scav.guardGate();
	scav.guardGate();
	copy.guardGate();
}