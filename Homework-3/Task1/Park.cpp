#include "Park.h"
#include "Appartment.h"

void Park::Purchase()
{
	if (Appartment::happiness < 100)
	{
		Appartment::happiness += 5 * (s / 100);
	}
	else
	{
		return;
	}
}
double Park::GetMonthCost() const
{
	return 0.0005 * cost * s;
}

Park::Park(string name, double cost, double s) : Building(name, cost, s) {};