#pragma once

#include <iostream>
#include "staff.h"

class manager : public staff {
public:
    manager(int number,string name,int job);
    ~manager();
    string responsibility() const;
};

