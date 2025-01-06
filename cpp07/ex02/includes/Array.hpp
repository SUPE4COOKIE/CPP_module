#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
private:
	T *_arr;
	unsigned int _size;
public:
	Array() : _arr(NULL), _size(0) {}
	Array(unsigned int n) : _arr(new T[n]), _size(n)
	{
		for (unsigned int i = 0; i < n; i++)
			_arr[i] = 0;
	}
	Array(Array const &other) : _arr(NULL), _size(0) { *this = other; }
	Array &operator=(Array const &ref)
	{
		if (this->_arr)
			delete[] this->_arr;
		this->_size = ref.size();
		this->_arr = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_arr[i] = ref._arr[i];
		return (*this);
	}
	T &operator[](unsigned int i)
	{
		if (i >= _size)
			throw std::out_of_range("Index out of range");
		return _arr[i];
	}
	unsigned int size() const { return _size; }
	~Array()
	{
		if (_arr)
			delete[] _arr;
	}
};


#endif