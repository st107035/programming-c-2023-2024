#include "B.h"
#include<iostream>

using namespace std;

B::B()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
	this->f[0] = 0;
	this->f[1] = 0;
	for (int i = 0; i < 42; ++i)
	{
		this->e[i] = 0;
	}
	this->h = 0;
	this->g = 0;
}

B::B(int a, int b, double c, double d, int f[2], char e[42], bool h, bool g)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->f[0] = f[0];
	this->f[1] = f[1];
	for (int i = 0; i < 42; ++i)
	{
		this->e[i] = e[i];
	}
	this->h = h;
	this->g = g;
}

void B::B_Allignment()
{
	cout << "Alignment of B" << std::endl;
	cout << " a " << offsetof(B, a) << endl;
	cout << " b " << offsetof(B, b) << endl;
	cout << " c " << offsetof(B, c) << endl;
	cout << " d " << offsetof(B, d) << endl;
	cout << " f " << offsetof(B, f) << endl;
	cout << " e " << offsetof(B, e) << endl;
	cout << " h " << offsetof(B, h) << endl;
	cout << " g " << offsetof(B, g) << endl;
}

B::~B() {};
