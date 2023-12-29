#pragma once
#include <exception>
#include <string>
#include <iostream>

using namespace std;

class Building
{
protected:
	string name;
	double cost;
	double s;
	static bool security;
	static bool medicine;
	static bool fire_security;
	static bool water;
	static bool electricity;

public:

	virtual double GetCost() const;
	virtual double GetS() const;
	virtual double GetMonthCost() const = 0;
	virtual string GetName() const;
	virtual void SetCost(double mcost);
	virtual void SetS(double s);
	virtual void Purchase() = 0;

	static bool GetElectricity();
	static bool GetWater();
	static bool GetSecurity();
	static bool GetMedicine();
	static bool GetFireSecurity();

	void Print() const;

	Building(string name = " ", double cost = 0, double s = 0);
	Building(const Building& b);
	virtual ~Building();
};

