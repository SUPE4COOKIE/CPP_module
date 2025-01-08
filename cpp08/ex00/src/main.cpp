#include <vector>
#include <list>
#include <cassert>
#include "easyfind.hpp"


int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(3);
	std::cout << *easyfind(vec, 2) << std::endl;
	*easyfind(vec, 2) = 0;
	std::cout << *easyfind(vec, 3) << std::endl << std::endl;
	*easyfind(vec, 3) = 0;

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl << "======================" << std::endl << std::endl;

	std::list<int> lst;
	lst.push_back(30);
	lst.push_back(10);
	lst.push_back(30);
	std::cout << *easyfind(lst, 10) << std::endl << std::endl;
	*easyfind(lst, 10) = 0;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;
	
	std::cout << std::endl << "======================" << std::endl << std::endl;

	int arr[] = {100, 200, 300};
	std::cout << *easyfind(arr, 100) << std::endl << std::endl;
	*easyfind(arr, 100) = 0;
	for (size_t i = 0; i < 3; ++i)
		std::cout << arr[i] << std::endl;

	return 0;
}