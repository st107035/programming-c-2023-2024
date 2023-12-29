#pragma once
#include "Infrastructure.h"
#include "Goods.h"
#include <vector>

class Manufacture :
    public Infrastructure
{
protected:

    unsigned specification;
    vector<Goods> v;
    unsigned productivity;

public:

    double SellGoods();
    Goods Produce();
    void Purchase() override;

    Manufacture(string name = " ", double cost = 0, double s = 0, unsigned level = 1, unsigned specification = 0);
    Manufacture(const Manufacture& m);
    ~Manufacture();
};

