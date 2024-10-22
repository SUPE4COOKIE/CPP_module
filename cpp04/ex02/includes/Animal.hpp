#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &);
	Animal &operator=(const Animal &);
	virtual ~Animal();

	virtual void makeSound() const;
	virtual std::string getType() const;
};
#endif