#include "Zombie.hpp"

void randomChump( std::string name)
{
	Zombie tmp;
	tmp.SetName(name);
	tmp.announce();
}