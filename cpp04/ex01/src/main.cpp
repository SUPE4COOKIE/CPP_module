#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[10];
	for (size_t i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (size_t i = 5; i < 10; i++)
		animals[i] = new Cat();

	for (size_t i = 0; i < 10; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
	Dog *dog = new Dog();
	Cat *cat = new Cat();
	Dog dogCopy = *dog;
	Cat catCopy = *cat;

	dog->setSound("*Bark*");
	cat->setSound("*Purr*");
	dog->makeSound();
	cat->makeSound();
	dogCopy.makeSound();
	catCopy.makeSound();
	delete dog;
	delete cat;
	return 0;
}