#pragma once
#include "Building.h"
#include <string>
class ResourceBuilding :
    public Building
{
protected:
	string specification; 

public:

	double GetMonthCost() const override;
	void Print();
	void Purchase() override;
	ResourceBuilding(string name = " ", double cost = 0, double s = 0, string specification = " ");
	ResourceBuilding(const ResourceBuilding& rb);
	~ResourceBuilding();
};

