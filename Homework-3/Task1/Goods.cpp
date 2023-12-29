#include "Goods.h"

using namespace std;

Goods::Goods(unsigned sp, double price) : specification(sp), price(price) {};

double Goods::GetPrice() const
{
	return price;
}