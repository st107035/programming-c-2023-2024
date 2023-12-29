#include "Manufacture.h"
#include "Goods.h"

Goods Manufacture::Produce()
{
	Goods temp = Goods(specification, level);
	v.push_back(temp);
	return temp;
}
double Manufacture::SellGoods()
{
	double temp = v.back().GetPrice();
	v.pop_back();
	return temp;
}
void Manufacture::Purchase()
{
	productivity = 2 * level;
}

Manufacture::Manufacture(string name,double cost, double s, unsigned level, unsigned specification) : Infrastructure(name, cost, s, level), specification(specification) 
{
	productivity = 0;
};
Manufacture::Manufacture(const Manufacture& m) : Infrastructure(m.name, m.cost, m.s, m.level), productivity(m.productivity) {};
Manufacture::~Manufacture() {};