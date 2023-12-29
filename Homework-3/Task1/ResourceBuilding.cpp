#include "ResourceBuilding.h"
#include "Appartment.h"

double ResourceBuilding::GetMonthCost() const
{
	return 0.005 * cost;
}
void ResourceBuilding::Purchase()
{
	if (specification == "Water")
	{
		water = 1;
		if (Appartment::happiness < 100)
		{
			Appartment::happiness += 2;
		}
		else
		{
			return;
		}
	}

	if (specification == "Electricity")
	{
		electricity = 1;
		if (Appartment::happiness < 100)
		{
			Appartment::happiness += 2;
		}
		else
		{
			return;
		}
	}
}
void ResourceBuilding::Print()
{
	cout << "Cost: " << cost << " area: " << s << " specification: " << specification << endl;
}
ResourceBuilding::ResourceBuilding(string name, double cost, double s, string specification) : Building(name, cost, s), specification(specification){};
ResourceBuilding::ResourceBuilding(const ResourceBuilding& rb) : Building(rb.name, rb.cost, rb.s) {};
ResourceBuilding::~ResourceBuilding() {};