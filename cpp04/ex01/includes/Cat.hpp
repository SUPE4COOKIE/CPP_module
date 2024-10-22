#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"
class Cat : public Animal
{
private:
	Brain *_brain;
	std::string _sound;
public:
	Cat();
	Cat(const Cat &);
	Cat &operator=(const Cat &);
	~Cat();

	void makeSound() const;
	void setSound(std::string sound);
	std::string getType() const;
};
#endif
