#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &);
	WrongAnimal &operator=(const WrongAnimal &);
	virtual ~WrongAnimal();

	void makeSound() const;
	virtual std::string getType() const;
};

#endif