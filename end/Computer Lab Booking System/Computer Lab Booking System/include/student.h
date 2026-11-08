#pragma once
#include "Person.h"
#include "order.h"
#include <iostream>
#include <string>
#include <vector>

class student : public Person {
public:
    student();

    student(int id,string name,string password);

    virtual void show_menu();

    void apply_booking();

    int my_booking();

    void view_booking();

    void delete_booking();

    bool logout();

    ~student();

    int stu_num;
};

