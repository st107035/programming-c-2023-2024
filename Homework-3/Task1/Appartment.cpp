#include "Appartment.h"

double Appartment::GetMonthCost() const
{
	switch (comfortclass)
	{
	case 1: return 0.001 * cost * s;
	case 2: return 0.001 * 1.5 * (cost * s);
	case 3: return 0.001 * 1.75 * (cost * s);
	case 4: return 0.001 * 2 * (cost * s);
	case 5: return 0.001 * 2.25 * (cost * s);
	}
}

unsigned Appartment::GetComfortclass() const
{
	return comfortclass;
}
unsigned Appartment::GetFloor() const
{
	return floor;
}
unsigned Appartment::GetHappiness()
{
	return happiness;
}
unsigned Appartment::GetPopulation() const 
{
	return population;
}

void Appartment::SetHappiness(int h)
{
	happiness += h;
}
void Appartment::Upgrade()
{
	if (comfortclass < 5)
	{
		comfortclass += 1;
		population += 3;
		global_population += 3;
	}
	else
	{
		throw exception("Your appartment has already been upgrated to the maximum level!");
	}
}
void Appartment::ResetTaxes()
{
	tax_flag = 0;
}
void Appartment::Purchase()
{
	population = 30 * floor * comfortclass *( 1 + (this->GetHappiness() / 100));
	global_population += population;
	count += 1;
}

Appartment::Appartment(string name, double cost, double s, unsigned comfortclass, unsigned floor) : Building(name, cost, s), comfortclass(comfortclass), floor(floor) {};
Appartment::Appartment(const Appartment& ap) : Building(ap.name, ap.cost, ap.s), comfortclass(ap.comfortclass), floor(ap.floor), population(ap.population) {};
Appartment::~Appartment() {};

