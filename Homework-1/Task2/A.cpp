#include "A.h"
#include <iostream>

using namespace std;

A::A()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
	for (int i = 0; i < 42; ++i)
	{
		this->e[i] = '0';
	}
	this->f[0] = 0;
	this->f[1] = 0;
	this->h = 0;
	this->g = 0;
}

A::A(int a, int b, double c, double d, char e[42], int f[2], bool h, bool g)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	for (int i = 0; i < 42; ++i)
	{
		this->e[i] = e[i];
	}
	this->f[0] = f[0];
	this->f[1] = f[1];
	this->h = h;
	this->g = g;
}

void A::A_Allignment()
{
	cout << "Alignment of A" << std::endl;
	cout << " a " << offsetof(A, a) << endl;
	cout << " b " << offsetof(A, b) << endl;
	cout << " c " << offsetof(A, c) << endl;
	cout << " d " << offsetof(A, d) << endl;
	cout << " e " << offsetof(A, e) << endl;
	cout << " f " << offsetof(A, f) << endl;
	cout << " h " << offsetof(A, h) << endl;
	cout << " g " << offsetof(A, g) << endl;
}

A::~A() {};
