#include "Array.hpp"

int main(void)
{
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i;
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;

	std::cout << std::endl << "=====================" << std::endl << std::endl;

	Array<int> arr2(arr);
	arr2[0] = 42;
	for (unsigned int i = 0; i < arr2.size(); i++)
		std::cout << arr[i] << " -> " << arr2[i] << std::endl;

	std::cout << std::endl << "=====================" << std::endl << std::endl;

	Array<int> arr3;
	arr3 = arr2;
	for (unsigned int i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << std::endl;

	std::cout << std::endl << "=====================" << std::endl << std::endl;

	Array<int> arr4(arr);
	try
	{
		for (unsigned int i = 0; i < arr4.size() + 1; i++)
			std::cout << arr4[i] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=====================" << std::endl << std::endl;

	Array<int> arr5;
	try
	{
		std::cout << arr5[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=====================" << std::endl << std::endl;

	Array<int> arr6(5);
	for (unsigned int i = 0; i < arr6.size(); i++)
		std::cout << arr6[i] << std::endl;

	std::cout << std::endl << "=====================" << std::endl << std::endl;

	Array<double> arr7(5);
	for (unsigned int i = 0; i < arr7.size(); i++)
		arr7[i] = i + i / 10.0;
	for (unsigned int i = 0; i < arr7.size(); i++)
		std::cout << arr7[i] << std::endl;
	return 0;
}