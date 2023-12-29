#pragma once
#include "Infrastructure.h"
#include <string>

class Service :
    public Infrastructure
{
protected:
    string specialization;

public:
    void Purchase() override;

    Service(string name = " ", double cost = 0, double s = 0, unsigned level = 1, string sp = " ");
    Service(const Service& sr);
    ~Service();
};

