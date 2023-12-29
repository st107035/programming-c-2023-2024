#include "Building.h"

double Building::GetCost() const
{
	return cost;
}
double Building::GetS() const
{
	return s;
}
bool Building::GetElectricity()  
{
	return electricity;
}
bool Building::GetWater()
{
	return water;
}
bool Building::GetSecurity()
{
	return security;
}
bool Building::GetMedicine() 
{
	return medicine;
}
bool Building::GetFireSecurity()
{
	return fire_security;
}
string Building::GetName() const
{
	return name;
}

void Building::SetCost(double mcost)
{
	//unique_lock<mutex> ul(mtx);
	if (mcost > 0)
	{
		this->cost = mcost;
	}
}
void Building::SetS(double s)
{
	//unique_lock<mutex> ul(mtx);
	if (s > 0)
	{
		this->s = s;
	}
}
void Building::Print() const
{
	cout << name << " | cost: " << cost << " area: " << s << endl;
}

Building::Building(string name, double cost, double s) : name(name), cost(cost), s(s) {};
Building::Building(const Building& b): name(b.name), cost(b.cost), s(b.s) {};
Building::~Building() {};