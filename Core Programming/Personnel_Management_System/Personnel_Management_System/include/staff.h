#pragma once
#include <string>
#include <iostream>
using namespace std;

class staff {


public:
    staff();
    virtual string responsibility() const =0;
    virtual ~staff();
    int number;
    string name;
    int job;
    
};

