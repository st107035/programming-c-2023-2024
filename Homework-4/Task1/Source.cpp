#include<iostream>
#include "Clist.h"
#define T int

using namespace std;

int main(int argc, char* argv[])
{
	int size;

	cin >> size;

	Clist<T> clist1(size);

	clist1.Print();
	cout << endl;

	for (int i = 0; i < size + 1; ++i)
	{
		clist1.AddTail(i);
		clist1.AddHead(i);
	}

	clist1.Print();
	cout << endl;

	clist1.Delete(size);

	clist1.Print();
	cout << endl;

	return EXIT_SUCCESS;
}