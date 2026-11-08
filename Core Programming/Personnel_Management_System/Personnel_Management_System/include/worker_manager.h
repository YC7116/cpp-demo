#pragma once

#include <iostream>
#include "worker_data.h"
ostream& operator<<(ostream& cout,const staff *s);
class worker_manager {
public:
    worker_manager();

    void show_menu();
    
    void sync_staff_info();

    // bool operator<(staff *s);

    // bool operator>(staff *s);

    void add();

    void display();

    void delet(int number);
    
    void delet(string name);


    void change(int number);

    void change(string name);

    void search(int number);

    void search(string name);

    void reverse(int choice);

    void clear();

    void  overwrite();

    
    ~worker_manager();

    static worker_data d;//其他类的对象作为另一类的成员变量
};

