#include "Span.hpp"
#include <ctime>

void subject_main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return ;
}

void huge_vector1()
{
	Span sp = Span(10000);
	std::vector<size_t> vec;
	for (size_t i = 0; i < 10000; i++)
		vec.push_back(i);
	sp.addNumber(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return ;
}

void huge_vector5()
{
	Span sp = Span(10000);
	std::vector<size_t> vec;
	for (size_t i = 0; i < 50000; i += 5)
		vec.push_back(i);
	sp.addNumber(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return ;
}

void huge_vector_random()
{
	srand(time(NULL));
	Span sp = Span(10000);
	std::vector<size_t> vec;
	for (size_t i = 0; i < 10000; i++)
		vec.push_back(rand());
	sp.addNumber(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void full_vector()
{
	Span sp = Span(5);
	std::vector<size_t> vec;
	for (size_t i = 0; i < 6; i++)
		vec.push_back(i);
	try
	{
		sp.addNumber(vec.begin(), vec.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// nothing added because vector is > capacity
	try
	{
		for (size_t i = 0; i < 6; i++)
			sp.addNumber(i);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// added 5 numbers
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

}

int main()
{
	subject_main();
	std::cout << std::endl << "====================" << std::endl << std::endl;
	huge_vector1();
	std::cout << std::endl << "====================" << std::endl << std::endl;
	huge_vector5();
	std::cout << std::endl << "====================" << std::endl << std::endl;
	huge_vector_random();
	std::cout << std::endl << "====================" << std::endl << std::endl;
	full_vector();
}