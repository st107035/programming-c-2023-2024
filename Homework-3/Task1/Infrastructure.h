#pragma once
#include "Building.h"
class Infrastructure :
    public Building
{
protected: 

    static unsigned employment_rate;
    unsigned level;
public:

    static bool revenue_flag;
    static double count;
    static double revenue;

    static void ResetRevenue();
    void Purchase() override;
    double GetRevenue() const;
    void Upgrade();
    double GetMonthCost() const override;
    unsigned GetLevel() const;

    Infrastructure(string name = " ", double cost = 0, double s = 0, unsigned level = 1);
    Infrastructure(const Infrastructure& inf);
    ~Infrastructure();
};

