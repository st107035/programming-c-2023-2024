#include <iostream>

class A
{
	int a, b;
	double c, d;
	char e[42];
	int f[2];
	bool h, g;

public: 
	A()
	{
		this->a = 0;
		this->b = 0;
		this->c = 0;
		this->d = 0;
		for (int i = 0; i < 42; ++i)
		{
			e[i] = 0;
		}
		f[0] = 0;
		f[1] = 0;
		h = true;
		g = false;

		std::cout << "Alignment of A" << std::endl;
		std::cout << " a " << offsetof(A, a) << std::endl;
		std::cout << " b " << offsetof(A, b) << std::endl;
		std::cout << " c " << offsetof(A, c) << std::endl;
		std::cout << " d " << offsetof(A, d) << std::endl;
		std::cout << " e " << offsetof(A, e) << std::endl;
		std::cout << " f " << offsetof(A, f) << std::endl;
		std::cout << " h " << offsetof(A, h) << std::endl;
		std::cout << " g " << offsetof(A, g) << std::endl;
	}
};

class B
{
	int a, b;
	double c, d;
	int f[2];
	char e[42];
	bool h, g;

public:
	B()
	{
		this->a = 0;
		this->b = 0;
		this->c = 0;
		this->d = 0;
		f[0] = 0;
		f[1] = 0;
		for (int i = 0; i < 42; ++i)
		{
			e[i] = 0;
		}
		h = true;
		g = false;

		std::cout << "Alignment of B" << std::endl;
		std::cout << " a " << offsetof(B, a) << std::endl;
		std::cout << " b " << offsetof(B, b) << std::endl;
		std::cout << " c " << offsetof(B, c) << std::endl;
		std::cout << " d " << offsetof(B, d) << std::endl;
		std::cout << " e " << offsetof(B, e) << std::endl;
		std::cout << " f " << offsetof(B, f) << std::endl;
		std::cout << " h " << offsetof(B, h) << std::endl;
		std::cout << " g " << offsetof(B, g) << std::endl;
	}
};

int main(int argc, char* argv[])
{
	A a;
	B b;
	return EXIT_SUCCESS;
}