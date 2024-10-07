#include "Zombie.hpp"

int main(void)
{
	Zombie *heap_zombie;
	Zombie stack_zombie("stack");

	heap_zombie = newZombie("heap");
	randomChump("chump");
	heap_zombie->announce();
	stack_zombie.announce();
	delete heap_zombie;
	return 0;
}