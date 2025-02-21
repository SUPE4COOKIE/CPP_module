#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	
public:
	MutantStack();
	~MutantStack();
	T &operator[](int index);
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
T &MutantStack<T>::operator[](int index)
{
	return this->c[index];
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	iterator it = other.begin();
	while (it != other.end())
	{
		this->push(*it);
		it++;
	}
	return *this;
}

#endif