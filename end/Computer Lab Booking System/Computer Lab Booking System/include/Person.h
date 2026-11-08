#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
    Person();
    Person(string name,string password);
    virtual void show_menu()=0;
    virtual ~Person();
protected:
    string name;
    string password;
};

