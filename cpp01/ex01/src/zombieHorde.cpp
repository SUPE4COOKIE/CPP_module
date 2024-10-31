#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde;

	if (N <= 0)
	{
		std::cerr << "Error: N must be greater than 0" << std::endl;
		return (NULL);
	}
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].SetName(name);
	}
	return (horde);
}