#pragma once

#include <iostream>
#include <string>
#include "boss.h"
#include "manager.h"
#include "employee.h"

class worker_data {
public:
    worker_data();
    void add_data(staff *staff);

    ~worker_data();
    
    staff *s[100]={ };
    int lenth=0;
};

