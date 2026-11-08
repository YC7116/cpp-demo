#include "employee.h"
#include <iostream>
#include <string>

employee::employee(int number,string name,int job) {
    this->number = number;
    this->name = name;
    this->job = job;
}
string employee:: responsibility() const{
    return "完成经理交给的任务";
}
employee::~employee() {
}

