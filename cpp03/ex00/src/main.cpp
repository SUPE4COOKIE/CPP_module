#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("clap");
	ClapTrap noname;
	ClapTrap copy(clap);

	clap.attack("copy");
	copy.takeDamage(5);
	std::cout << "copy hp: " << copy.GetHp() << std::endl;
	std::cout << "clap hp: " << clap.GetHp() << std::endl;
	copy.beRepaired(5);
	std::cout << "copy hp: " << copy.GetHp() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		clap.attack("copy");
	}
}