#include "Infrastructure.h"
#include "Appartment.h"

double Infrastructure::GetRevenue() const
{
	if (!revenue_flag)
	{
		return 0.05 * cost * level;
	}
}
void Infrastructure::Purchase()
{
	count += 1;
	employment_rate += (5 * s * level) * 100 / Appartment::global_population;
	Appartment::global_population_limit += 50 * level;
}
void Infrastructure::Upgrade()
{
	if (level < 5)
	{
		level += 1;
	}
	else
	{
		throw exception("Your infrastructure reached the maximum level!");
	}
	Appartment::global_population_limit += (5 * level);
	employment_rate += (5 * level) * 100 / Appartment::global_population;
}
double Infrastructure::GetMonthCost() const 
{
	return 0.001 * cost * s * level;
}
void Infrastructure::ResetRevenue()
{
	revenue_flag = 0;
}
unsigned Infrastructure::GetLevel() const
{
	return level;
}

Infrastructure::Infrastructure(string name, double cost, double s, unsigned level) : Building(name, cost, s), level(level) {};
Infrastructure::Infrastructure(const Infrastructure& inf) : Building(inf.name, inf.cost, inf.s), level(inf.level) {};
Infrastructure::~Infrastructure() {};