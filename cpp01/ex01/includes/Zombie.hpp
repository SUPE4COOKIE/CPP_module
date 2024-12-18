#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
private:
	std::string name;
public:
	void announce();
	Zombie();
	void SetName(std::string name);
	~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name);
#endif
