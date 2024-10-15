#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clap("clap");
	FragTrap Frag("Frag");
	FragTrap copy(Frag);

	Frag.attack("copy");
	copy.takeDamage(5);
	std::cout << "copy hp: " << copy.GetHp() << std::endl;
	copy.beRepaired(5);
	copy.takeDamage(5);
	std::cout << "copy hp: " << copy.GetHp() << std::endl;
	for (int i = 0; i < 11; i++)
	{
		Frag.attack("copy");
		copy.takeDamage(Frag.GetAtk());
	}
	Frag.highFivesGuys();
	copy.highFivesGuys();
}