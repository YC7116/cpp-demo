#pragma once
#include "staff.h"
#include <iostream>

class boss : public staff {
public:
    boss(int number,string name,int job);
    string responsibility() const;
    ~boss();
};

