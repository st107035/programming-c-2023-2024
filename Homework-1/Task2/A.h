#pragma once
class A
{
private:

	int a, b;
	double c, d;
	char e[42];
	int f[2];
	bool h, g;

public:

	A();
	A(int a, int b, double c, double d, char e[42], int f[2], bool h, bool g);

	void A_Allignment();

	~A();
};

