#pragma once
#include "Person.h"
#include <iostream>
#include <string>
#include <vector>

class admin : public Person {
public:
    admin();

    admin(string name,string password);

    virtual void show_menu();

    void add_account();

    void view_account();

    void view_computer_room();

    void clear_booking();

    bool logout();

    ~admin();
};

