#include "GovernmentBuilding.h"

void GovernmentBuilding::ChangeTaxes(int percentage)
{
	if ((percentage > -100) && (percentage < 100))
	{
		Appartment::taxes += percentage / (100 * Appartment::taxes);
	}
	else
	{
		throw exception("Percentage of increase/decrease of taxes/revenue shoulb be between - 100% and 100%!");
	}
}
void GovernmentBuilding::ChangeRevenue(int percentage)
{
	if ((percentage > -100) && (percentage < 100))
	{
		Infrastructure::revenue += percentage / (100 * Infrastructure::revenue);
	}
	else
	{
		throw exception("Percentage of increase/decrease of taxes/revenue shoulb be between - 100% and 100%!");
	}
}
double GovernmentBuilding::GetMonthCost() const
{
	return 0.005 * cost * s;
}
void GovernmentBuilding::GetAllTaxes()
{
	treasury += Appartment::count * Appartment::taxes;
	Appartment::tax_flag = 1;
}
void GovernmentBuilding::GetAllRevenue()
{
	treasury += Infrastructure::count * Infrastructure::revenue;
	Infrastructure::revenue_flag = 1;
}
void GovernmentBuilding::Purchase()
{
	Appartment::SetHappiness(2);
}

GovernmentBuilding::GovernmentBuilding(string name, double cost, double s) : Building(name, cost, s) {};
GovernmentBuilding::GovernmentBuilding(const GovernmentBuilding& gb) : Building(gb.name, gb.cost, gb.s) {};
GovernmentBuilding::~GovernmentBuilding() {};