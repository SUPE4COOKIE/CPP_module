#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>
# include <list>
# include <stdexcept>

template <typename T, typename U> 
U *easyfind(T &container, U nbr)
{
	for (typename T::iterator i = container.begin(); i != container.end(); ++i)
	{
		if (*i == nbr)
			return &(*i);
	}
	return (NULL);
}

template <typename U, size_t N>
U *easyfind(U (&array)[N], U nbr)
{
	for (size_t i = 0; i < N; ++i)
	{
		if (array[i] == nbr)
			return (&(array[i]));
	}
	return (NULL);
}
#endif