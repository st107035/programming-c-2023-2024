#include "Building.h"

Building::Building(double mcost, double s) : mcost(mcost), s(s) {};

double Building::GetMcost()
{
	return mcost;
}

double Building::GetS()
{
	return s;
}

void Building::SetMcost(double mcost)
{
	if (mcost > 0)
	{
		this->mcost = mcost;
	}
}

void Building::SetS(double s)
{
	if (s > 0)
	{
		this->s = s;
	}
}