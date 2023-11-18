#pragma once
#include "Building.h"
class CountryHouse :
    public Building
{
protected: 
    bool gaz, electricity, canalization;
public: 
    CountryHouse(double mcost = 0, double s = 0, bool gaz = 0, bool electricity = 0, bool canalization = 0);
    double price() const;

    bool GetGaz();
    bool GetElectricity();
    bool GetCanalization();
    void SetGaz(bool gaz);
    void SetElectricity(bool electricity);
    void SetCanalization(bool canalization);

    ~CountryHouse() {};
};

