#include "boss.h"
#include <iostream>

boss::boss(int number,string name,int job) {
    this->number = number;
    this->name = name;
    this->job = job;
}
string boss:: responsibility() const{
    return "管理公司所有事务";
}
boss::~boss() {
}

