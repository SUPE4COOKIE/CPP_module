#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *tmp;
	tmp = new Zombie;
	tmp->SetName(name);
	return (tmp);
}