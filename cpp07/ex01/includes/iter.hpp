#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>

template <typename T, typename U, typename V>
void iter(T addr, U len, V func)
{
	for (long i = 0; i < len; i++)
	{
		func(&addr[i]);
	}
}
#endif