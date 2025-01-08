#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <stdexcept>

# define ABS(x) ((x) < 0 ? -(x) : (x))

class Span
{
private:
	std::vector<size_t> _data;
	std::size_t _capacity;
	static std::runtime_error _SpanException;
public:
	Span();
	Span(size_t size);
	Span(Span const &ref);
	Span &operator=(Span const &ref);
	~Span();

	void addNumber(std::size_t nbr);
	
	size_t shortestSpan();
	size_t longestSpan();

	size_t getSize() const;
};

#endif