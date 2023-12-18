#include<iostream>
#include "Sample.h"

using namespace std;

int Sample::f1()
{
	cout << "Function f1 of Sample has been finished" << endl;
	return 0;
}

void Sample::f2()
{
	cout << "Function f2 of Sample has been finished" << endl;
}

char Sample::f3()
{
	cout << "Function f3 of Sample has been finished" << endl;
	return '0';
}

Sample::Sample(int a = 0) : a(a) {};

Sample::~Sample() {};