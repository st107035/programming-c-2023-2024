#pragma once
class B
{
private:

	int a, b;
	double c, d;
	int f[2];
	char e[42];
	bool h, g;

public:

	B();

	B(int a, int b, double c, double d, int f[2], char e[42], bool h, bool g);

	void B_Allignment();

	~B();
};

