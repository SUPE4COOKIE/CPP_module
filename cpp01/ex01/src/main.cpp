#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;

	horde = zombieHorde(5, "bob");
	if (horde == NULL)
		return (1);
	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
}