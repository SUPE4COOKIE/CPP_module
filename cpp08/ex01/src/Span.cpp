#include "Span.hpp"

std::runtime_error Span::_SpanException = std::runtime_error("Span exception");

Span::Span() : _data(), _capacity(0) {}
Span::Span(size_t size) : _capacity(size) {}
Span::Span(Span const &ref) : _data(ref._data), _capacity(ref._capacity) {}
Span &Span::operator=(Span const &ref) { this->_data = ref._data; this->_capacity = ref._capacity; return *this; }
std::size_t Span::getSize() const { return this->_data.size(); }
Span::~Span() {}

void Span::addNumber(std::size_t nbr)
{
	if (this->_data.size() + 1 > this->_capacity)
		throw this->_SpanException;
	this->_data.push_back(nbr);
}

void Span::addNumber(std::vector<size_t>::iterator begin, std::vector<size_t>::iterator end)
{
	if (this->_data.size() + std::distance(begin, end) > this->_capacity)
		throw this->_SpanException;
	this->_data.insert(this->_data.end(), begin, end);
}

std::size_t Span::shortestSpan()
{
	if (this->_data.size() < 2)
		throw this->_SpanException;
	size_t min = this->_data[0];
	for (size_t i = 0; i < this->_data.size(); i++)
	{
		for (size_t j = 0; j < this->_data.size(); j++)
		{
			if (i != j)
			{
				if (ABS(this->_data[i] - this->_data[j]) < min)
					min = ABS(this->_data[i] - this->_data[j]);
			}
		}
	}
	return (min);
}

std::size_t Span::longestSpan()
{
	if (this->_data.size() < 2)
		throw this->_SpanException;
	size_t smallest;
	size_t biggest;
	for (size_t i = 0; i < this->_data.size(); i++)
	{
		if (i == 0)
		{
			smallest = this->_data[i];
			biggest = this->_data[i + 1];
		}
		else
		{
			if (this->_data[i] < smallest)
				smallest = this->_data[i];
			else if (this->_data[i] > biggest)
				biggest = this->_data[i];
		}
	}
	return biggest - smallest;
}
