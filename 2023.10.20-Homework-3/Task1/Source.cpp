#include <iostream>
#include <ctime>
#include "Building.h"
#include "Appartment.h"
#include "CountryHouse.h"
using namespace std;

int main(int argc, char* argv[])
{
	cout << "Welcome to the game!" << endl;
	cout << "Please, write the difficulty level from 1 to 3" << endl;

	{
	int n = 0;
	int money = 0;
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "Your level is easy. Your amount of money is 75M$" << endl;
		money = 75000;
		break;
	case 2:
		cout << "Your level is normal. Your amount of money is 25M$" << endl;
		money = 25000;
		break;
	case 3:
		cout << "Your level is hard. Your amount of money is 10M$" << endl;
		money = 10000;
		break;
	}
	}

	{
		cout << "Choose your place: " << endl;
		int ch1 = 0;
		cin >> ch1;
		Building** B = new Building* [10];
		srand(time(0));
		for (int i = 0; i <= 9; ++i)
			{
			if (i <= 4)
				{
					B[i] = new Appartment(rand() % 1001 + 100, rand() % 101 + 20, rand() & 9 + 1, rand() % 6 + 1);
					cout << i << " Price: " << B[i]->price() << " Space: " << B[i]->GetS() << " Floor: " << B[i]->GetFloor() << " Comfort Class: " << B[i]->GetComfortclass() << endl;
				}
			else
				{
					B[i] = new CountryHouse(rand() % 1001 + 100, rand() % 201 + 50, rand() % 2, rand() % 2, rand() % 2);
					cout << i << " Price: " << B[i]->price() << " Space: " << B[i]->GetS() << " Gaz: " << B[i]->GetGaz() << " Electricity: " << B[i]->GetElectricity() << " Canalization: " << B[i]->GetCanalization() << endl;
				}
			}
	}
	return EXIT_SUCCESS;
}