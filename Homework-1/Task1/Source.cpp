#include<iostream>
#include "Sample.h"
#include "Sample1.h"

using namespace std;

int main(int argc, char* argv[])
{
	Sample s1(4); 

	Sample1 s2(5);

	Sample* p = &s2;

	int a = p->f1();
	p->f2();
	char b = p->f3();

	return EXIT_SUCCESS;
}