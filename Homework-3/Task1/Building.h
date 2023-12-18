#pragma once
class Building
{
protected:
	double mcost;
	double s;

	Building(double mcost = 0, double s = 0);
public:
	virtual double price() const = 0;
	double GetMcost();
	double GetS();
	void SetMcost(double mcost);
	void SetS(double s);

	virtual double GetFloor() = 0;
	virtual double GetComfortclass() = 0;
	virtual void SetFloor(int floor) = 0;
	virtual void SetComfortclass(int comfortclass) = 0;

	virtual bool GetGaz() = 0;
	virtual bool GetElectricity() = 0;
	virtual bool GetCanalization() = 0;
	virtual void SetGaz(bool gaz) = 0;
	virtual void SetElectricity(bool electricity) = 0;
	virtual void SetCanalization(bool canalization) = 0;
	

	virtual ~Building() {};
};

