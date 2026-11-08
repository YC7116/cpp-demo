#include "manager.h"
#include <iostream>
#include "staff.h"

manager::manager(int number, string name, int job)
{
    this->number = number;
    this->name = name;
    this->job = job;
}

string manager::responsibility() const
{
    return "完成老板交给的任务，并下发任务给员工";
}
manager::~manager()
{
}
