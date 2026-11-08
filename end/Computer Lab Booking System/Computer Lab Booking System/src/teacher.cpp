#include "teacher.h"
#include "config.h"
#include "File.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

teacher::teacher()
{
}

void teacher::show_menu()
{
    cout << "欢迎教师：" << this->name << "登录！" << endl;
    cout << "        ----------------------------------" << endl;
    cout << "        |                                |" << endl;
    cout << "        |           1. 查看所有预约      |" << endl;
    cout << "        |                                |" << endl;
    cout << "        |           2. 审核预约          |" << endl;
    cout << "        |                                |" << endl;
    cout << "        |           0. 注销登录          |" << endl;
    cout << "        |                                |" << endl;
    cout << "        ----------------------------------" << endl;
}

teacher::teacher(int staff_num, string name, string password) : Person(name, password)
{
    this->staff_num = staff_num;
}

void teacher::all_booking()
{
    int i = 1;
    for (vector<order>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << i << "、" << "预约日期：" << it->date << "  时段：" << it->time << "  学号："
             << it->num << "  名字：" << it->name << "  机房："
             << it->room_num << "  状态：" << it->state << endl;
        i++;
    }
}

void teacher::check_booking()
{
    File f;
    cout << "待审核的预约记录如下：" << endl;
    int choice = 0;
    int i = 1;
    map<int, vector<order>::iterator> i_index;
    for (vector<order>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->state == UNDERREVIEW)
        {
            cout << i << "、" << "预约日期：" << it->date << "时段：" << it->time << "机房：" << it->room_num << "状态：" << it->state << endl;
            i_index.insert(make_pair(i, it));
            i++;
        }
    }
    cout << "请输入审核的预约记录，其他代表返回：" << endl;
    while (!(cin >> choice))
    {
        cout << "审核的预约号应为整数，请重新输入：" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (choice >= 1 && choice <=(int)i_index.size())
    {
        cout << "请输入审核结果：\n1、通过\n2、不通过" << endl;
        int pass;
        while (!(cin >> pass) || pass<1 || pass>2)
        {
            cout << "选择号应为整数且为1或2，请重新输入：" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        if(pass==1){
            i_index.at(choice)->state = SUCCESS;
            f.write_order();
        }
        else if(pass==2){
            i_index.at(choice)->state = FAIL;
            f.write_order();
        }
        
    }
    else{
        cout<<"该预约号不存在"<<endl;
    }
}

bool teacher::logout()
{
    return true;
}

teacher::~teacher()
{
}
