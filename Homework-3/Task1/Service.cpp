#include "Service.h"
#include "Appartment.h"

//void Service::SetFireSecurity()
//{
//	if (specialization == "Fire Security")
//	{
//		fire_security = 1;
//	}
//}
//void Service::SetMedicine()
//{
//	if (specialization == "Medicine")
//	{
//		medicine = 1;
//	}
//}
//void Service::SetSecurity()
//{
//	if (specialization == "Security")
//	{
//		security = 1;
//	}
//}

void Service::Purchase()
{
	if (specialization == "Fire Security")
		{
			fire_security = 1;
			if (Appartment::happiness < 100)
			{
				Appartment::happiness += 5 * level;
			}
			else
			{
				return;
			}
		}
	if (specialization == "Medicine")
		{
			medicine = 1;
			if (Appartment::happiness < 100)
			{
				Appartment::happiness += 5 * level;
			}
			else
			{
				return;
			}
		}
	if (specialization == "Security")
		{
			security = 1;
			if (Appartment::happiness < 100)
			{
				Appartment::happiness += 5 * level;
			}
			else
			{
				return;
			}
		}
}

Service::Service(string name, double cost, double s, unsigned level, string sp) : Infrastructure(name, cost, s, level), specialization(sp) {};
Service::Service(const Service& sr) : Infrastructure(sr.name, sr.cost, sr.s, sr.level), specialization(sr.specialization) {};
Service::~Service() {};