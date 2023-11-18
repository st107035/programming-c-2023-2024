#include "Appartment.h"
Appartment::Appartment(double mcost, double s, int floor, int comfortclass) : Building(mcost, s), floor(floor), comfortclass(comfortclass) {};

double Appartment::price() const
{
	switch (comfortclass)
	{
	case 1: return mcost * s + 1.005 * floor;
	case 2: return 1.5 * (mcost * s + 1.005 * floor);
	case 3: return 1.75 * (mcost * s + 1.005 * floor);
	case 4: return 2 * (mcost * s + 1.005 * floor);
	case 5: return 2.25 * (mcost * s + 1.005 * floor);
	}
}

double Appartment::GetFloor()
{
	return floor;
}
double Appartment::GetComfortclass()
{
	return comfortclass;
}
void Appartment::SetFloor(int floor)
{
	if (floor >= 0)
	{
		this->floor = floor;
	}
}
void Appartment::SetComfortclass(int comfortclass)
{
	if ((comfortclass >= 0) && (comfortclass <= 5))
	{
		this->comfortclass = comfortclass;
	}
}