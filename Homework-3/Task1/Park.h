#pragma once
#include "Building.h"
class Park :
    public Building
{
public:
    void Purchase() override;
    double GetMonthCost() const override;

    Park(string name = " ", double cost = 0, double s = 0);
};

