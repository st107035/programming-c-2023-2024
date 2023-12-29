#pragma once

class Goods
{
protected:

	unsigned specification;
	double price;
public:
	
	double GetPrice() const;
	Goods(unsigned sp = 0, double price = 0);
};

