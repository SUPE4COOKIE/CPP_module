#include "iter.hpp"

void iadd5(int *a)
{
	*a += 5;
}

void dadd5(double *a)
{
	*a += 5;
}

int main(void)
{
	int iarr[] = {1, 2, 3, 4, 5};
	iter(iarr, 5, iadd5);
	for (int i = 0; i < 5; i++)
		std::cout << iarr[i] << std::endl;

	double darr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double dlen = 5;
	iter(darr, dlen, dadd5);
	for (int i = 0; i < 5; i++)
		std::cout << darr[i] << std::endl;
	return 0;
}