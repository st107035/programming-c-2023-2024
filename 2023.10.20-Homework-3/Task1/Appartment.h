#pragma once
#include "Building.h"
class Appartment :
    public Building
{
protected: 
    int floor;
    int comfortclass;
public: 
    Appartment(double mcost = 0, double s = 0, int floor = 1, int comfortclass = 1);

    double price() const;
    double GetFloor();
    double GetComfortclass();
    void SetFloor(int floor);
    void SetComfortclass(int comfortclass);

    ~Appartment() {};
};

