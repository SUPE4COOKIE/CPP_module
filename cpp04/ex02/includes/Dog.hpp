#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
	std::string _sound;
public:
	Dog();
	Dog(const Dog &);
	Dog &operator=(const Dog &);
	~Dog();

	void makeSound() const;
	void setSound(std::string sound);
	std::string getType() const;
};

#endif