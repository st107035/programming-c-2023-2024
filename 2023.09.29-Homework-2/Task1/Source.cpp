#include <iostream>
#include "Z239Z.h"

int mod(int a, int n)
{
	if (a % n < 0)
	{
		return a % n + n;
	}
	else
	{
		return a % n;
	}
}

int main(int argc, char* argv[])
{
	Z239Z z1(-2400);
	Z239Z z2(352);

	Z239Z z3;
	z3 = z1 + z2;

	std::cout << z3 << std::endl;

	Z239Z z4;

	std::cin >> z4;
	std::cout << z4 << std::endl;

	z4 *= z3;
	std::cout << z4;

	return EXIT_SUCCESS;
}