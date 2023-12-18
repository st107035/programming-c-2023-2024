#include "CountryHouse.h"

CountryHouse::CountryHouse(double mcost, double s, bool gaz, bool electricity, bool canalization) : Building(mcost, s), gaz(gaz), electricity(electricity), canalization(canalization) {};

double CountryHouse::price() const
{
	return (mcost * s) * (1.05 * gaz + 1.1 * electricity + 1.5 * canalization);
}

bool CountryHouse::GetGaz()
{
	return gaz;
}
bool CountryHouse::GetElectricity()
{
	return electricity;
}
bool CountryHouse::GetCanalization()
{
	return canalization;
}
void CountryHouse::SetGaz(bool gaz)
{
	if ((gaz == 0) || (gaz == 1))
	{
		this->gaz = gaz;
	}
}
void CountryHouse::SetElectricity(bool electricity)
{
	if ((electricity == 0) || (electricity == 1))
	{
		this->electricity = electricity;
	}
}
void CountryHouse::SetCanalization(bool canalization)
{
	if ((canalization == 0) || (canalization == 1))
	{
		this->canalization = canalization;
	}
}