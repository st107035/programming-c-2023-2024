#pragma once
#include "Building.h"

class Appartment :
    public Building
{
protected: 

    unsigned comfortclass;
    unsigned population; 
    unsigned floor;

public:

    static unsigned happiness;
    static int count;
    static double taxes;
    static unsigned global_population; 
    static unsigned global_population_limit;
    static bool tax_flag;

    double GetMonthCost() const override;

    unsigned GetComfortclass() const;
    unsigned GetFloor() const;
    static unsigned GetHappiness();
    unsigned GetPopulation() const;
    void Purchase() override;
    static void ResetTaxes();
    static void SetHappiness(int h);
    void Upgrade();

    Appartment(string name = " ", double cost = 0, double s = 0, unsigned comfortclass = 1, unsigned floor = 1);
    Appartment(const Appartment& ap);
    ~Appartment();
};

