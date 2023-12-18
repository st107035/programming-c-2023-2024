#include "Sample1.h"
#include<iostream>

using namespace std;

int Sample1::f1()
{
	cout << "Function f1 of Sample1 has been finished" << endl;
	return 0;
}

void Sample1::f2()
{
	cout << "Function f2 of Sample1 has been finished" << endl;
}

char Sample1::f3()
{
	cout << "Function f3 of Sample1 has been finished" << endl;
	return '0';
}

Sample1::Sample1(int a = 0) : Sample(a) {};
Sample1::~Sample1(){};