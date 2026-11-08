#pragma once
#include "staff.h"
#include <iostream>
#include <string>

class employee : public staff {
public:
    employee(int number,string name,int job);
    ~employee();

    string responsibility() const;
};

