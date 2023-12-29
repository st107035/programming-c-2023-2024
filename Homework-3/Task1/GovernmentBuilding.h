#pragma once
#include "Building.h"
#include "Appartment.h"
#include "Infrastructure.h"

class GovernmentBuilding :
    public Building
{
protected: 
    static double treasury;

public:

    void ChangeTaxes(int percentage);
    void ChangeRevenue(int percentage);
    double GetMonthCost() const override;
    void GetAllTaxes();
    void GetAllRevenue();
    void Purchase() override;

    GovernmentBuilding(string name = " ", double cost = 0, double s = 0);
    GovernmentBuilding(const GovernmentBuilding& gb);
    ~GovernmentBuilding();
};

