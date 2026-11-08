#pragma once
#include "Person.h"
#include "order.h"
#include <iostream>
#include <string>
#include <vector>

class teacher : public Person {
public:
    teacher();

    teacher(int staff_num,string name,string password);

    virtual void show_menu();

    void all_booking();

    void check_booking();

    bool logout();
    ~teacher();

    int staff_num;
};

