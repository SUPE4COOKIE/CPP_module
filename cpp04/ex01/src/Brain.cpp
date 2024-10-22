#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain has been created!" << std::endl;
}

Brain::Brain(const Brain &ref)
{
	*this = ref;
	std::cout << "Brain has been copied!" << std::endl;
}

Brain &Brain::operator=(const Brain &ref)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ref._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain has been destroyed!" << std::endl;
}