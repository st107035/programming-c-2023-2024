#include <list>
#include <ctime>
#include <conio.h>
#include "Appartment.h"
#include "Infrastructure.h"
#include "ResourceBuilding.h"
#include "GovernmentBuilding.h"
#include "Manufacture.h"
#include "Park.h"
#include "Service.h"

using namespace std;

bool Building::water = 0;
bool Building::electricity = 0;
bool Building::security = 0;
bool Building::medicine = 0;
bool Building::fire_security = 0;
int Appartment::count = 0;
double Appartment::taxes = 13;
unsigned Appartment::global_population = 0; 
unsigned Appartment::global_population_limit = 1000;
bool Appartment::tax_flag = 0;
unsigned Appartment::happiness = 20;
bool Infrastructure::revenue_flag = 0;
double Infrastructure::count = 0;
double Infrastructure::revenue = 13;
unsigned Infrastructure::employment_rate = 100;
double GovernmentBuilding::treasury = 0;

unsigned money = 0;

bool emergency1()
{
	if ((Building::GetWater() == 0) || (Building::GetElectricity() == 0))
	{
		cout << "======== WARNING! ========" << endl;
		cout << "Your town is run out of water or electricity! Consdier buying resource buildings!\n" << endl;
		return true;
	}
	return false;
}
bool emergency2()
{
	if (Building::GetSecurity() == 0)
	{
		cout << "======== WARNING! ========" << endl;
		cout << "Your town has no security! Consdier buying service buildings!\n" << endl;
		return true;
	}
	return false;
}
bool emergency3()
{
	if (Building::GetFireSecurity() == 0)
	{
		cout << "======== WARNING! ========" << endl;
		cout << "Your town has no fire security! Consdier buying service buildings!\n" << endl;
		return true;
	}
	return false;
}
bool emergency4()
{
	if (Building::GetMedicine() == 0)
	{
		cout << "======== WARNING! ========" << endl;
		cout << "Your town has no medical help! Consdier buying service buildings!\n" << endl;
		return true;
	}
	return false;
}
bool emergency5()
{
	if (Appartment::GetHappiness() <= 40)
	{
		cout << "======== WARNING! ========" << endl;
		cout << "Your town is unhappy! Consdier buying more parks!\n" << endl;
		return true;
	}
	return false;
}

void TownInformation()
{
	cout << "======== TOWN INFORMATION ========\n" << endl;
	cout << "Global population: " << Appartment::global_population << endl;
	cout << "Global population limit: " << Appartment::global_population_limit << endl;
	cout << "Resources and services indicators: " << endl;
	cout << "Water: " << Building::GetWater() << endl;
	cout << "Electricity: " << Building::GetElectricity() << endl;
	cout << "Security: " << Building::GetSecurity() << endl;
	cout << "Fire security: " << Building::GetFireSecurity() << endl;
	cout << "Medicine: " << Building::GetMedicine() << endl;
	cout << "Happiness: " << Appartment::happiness << "%" << endl;
	cout << "Money: " << money << endl;
	cout << endl;
	system("pause");
	system("cls");
}
void PrintList(const list<Building*>& lst, bool number_flag)
{
	unsigned i = 0;

	for (auto it = lst.begin(); it != lst.end(); ++it)
	{
		++i;
		auto temp = *it;
		if (number_flag)
		{
			cout << i << " ";
		}
		temp->Print();
	}
	cout << endl;
	cout << "To purchase a building, enter its number\n" << endl;
	system("pause");
}
void Purchase(const list<Building*>& shop_list, list<Building*>& lst)
{
	auto it = shop_list.begin();
	unsigned choice;
	cin >> choice;
	advance(it, choice - 1);
	auto temp = *it;
	if (money - temp->GetCost() >= 0)
	{
		money -= temp->GetCost();
		temp->Purchase();
		lst.push_back(temp);
		cout << "You bought " << temp->GetName() << " | " << typeid(*(*it)).name() << endl;
	}
	else
	{
		cout << "You dont have enough money!" << endl;
	}
	system("pause");
	system("cls");
}
void MonthlyPayment(const list<Building*>& lst)
{
	double total = 0;
	cout << "======== Its time for a montly payment! ========\n" << endl;
	for (auto i : lst)
	{
		cout << i->GetName() << " have monthly cost of " << i->GetMonthCost() << "$\n";
		money -= i->GetMonthCost();
		total += i->GetMonthCost();
	}
	cout << "TOTAL: " << total << endl;
	cout << "Your balance: " << money << endl;
	cout << endl;
	system("pause");
}
void GetMoney(list<Building*>& lst)
{
	cout << "======== Its time to gain money from your city! ========" << endl;
	cout << "To show the taxes and revenue of your buildings, press m, unless press any other letter\n" << endl;
	char c = _getch();
	if (c == 'm')
	{
		for (auto it : lst)
		{
			cout << 
		}
	}
}
void OpenShop(const list<Building*>& shop_list, list<Building*>& lst)
{
	cout << "======== Welcome to the shop! ========\n" << endl;
	PrintList(shop_list, 1);
	Purchase(shop_list, lst);
}
void Help()
{
	cout << "======== Here are the instructions! ========\n" << endl;
	cout << "Press i if you want to get Town Information" << endl;
	cout << "Press s if you want to open the shop" << endl;
	cout << "Press h if you want to read the instructions" << endl;
	cout << "Press e if you want to exit" << endl;
}
void GameStep(const list<Building*>& shop_list, list<Building*>& lst)
{
	char c = _getch();
	switch(c)
	{
	case 'i':
		TownInformation();
		break;
	case 's':
		OpenShop(shop_list, lst);
		break;
	case 'h':
		Help();
		break;
	case 'e':
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char* argv[])
{
	int time = 0;

	cout << "======== Welcome to the game! ========\n" << endl;
	cout << "Please, write the difficulty level from 1 to 3" << endl;
	unsigned n;
	cin >> n;
	cout << endl;
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
	system("pause");
	Help();
	cout << endl;

	list<Building*> l;
	list<Building*> shop_list;

	shop_list.push_back(new Appartment("Casual appartment building", 1500, 100, 1, 3));
	shop_list.push_back(new Appartment("Town appartment building", 2500, 120, 1, 5));
	shop_list.push_back(new Appartment("Block of flat", 3000, 125, 2, 7));
	shop_list.push_back(new ResourceBuilding("Water tower", 200, 20, "Water"));
	shop_list.push_back(new ResourceBuilding("Windmill", 300, 20, "Electricity"));
	shop_list.push_back(new Infrastructure("Cafe", 1000, 30, 1));
	shop_list.push_back(new Infrastructure("Small shop", 2000, 40, 2));
	shop_list.push_back(new Infrastructure("Cinema", 2500, 200, 1));
	shop_list.push_back(new Service("Little hospital", 400, 50, 1, "Medicine"));
	shop_list.push_back(new Service("Little police station", 500, 50, 1, "Security"));
	shop_list.push_back(new Service("Little fire station", 600, 60, 1, "Fire Security"));
	shop_list.push_back(new GovernmentBuilding("Little town hall", 3000, 100));
	shop_list.push_back(new Park("Little town park", 200, 80));
	shop_list.push_back(new Park("Middle town park", 500, 120));

	while (money != 0)
	{
		GameStep(shop_list, l);

		while (emergency1() || emergency2() || emergency3() || emergency4() || emergency5())
		{
			GameStep(shop_list, l);
		}

		++time;
		if (time == 30)
		{
			MonthlyPayment(l);
			cout << "Your mounth is over! Your city is thriving! " << endl;
			time = 0;
		}
		system("cls");
	}

	return EXIT_SUCCESS;
}