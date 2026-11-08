#include "admin.h"
#include "config.h"
#include "File.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

admin::admin()
{
}

admin::admin(string name, string password) : Person(name, password)
{
}

void admin::show_menu()
{
    cout << "欢迎管理员:" << this->name << "登录！" << endl;
    cout << "        ----------------------------------" << endl;
    cout << "        |                                |" << endl;
    cout << "        |           1. 添加账号          |" << endl;
    cout << "        |           2. 查看账号          |" << endl;
    cout << "        |           3. 查看机房          |" << endl;
    cout << "        |           4. 清空预约          |" << endl;
    cout << "        |           0. 注销登录          |" << endl;
    cout << "        |                                |" << endl;
    cout << "        ----------------------------------" << endl;
}

void admin::add_account()
{
    File f;
    int num;
    string name;
    string password;
    string file_name;
    cout << "请输入你要添加的账号的类型：\n1、添加学生\n2、添加老师" << endl;
    int choice = 0;
    while (!(cin >> choice) || choice < 1 || choice > 2)
    {
        cout << "序号应为整数且为1或2之间，请重新输入：" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (choice == 1)
    {
        cout << "请输入学号：" << endl;
        while (!(cin >> num))
        {
            cout << "学号应为整数，请重新输入：" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        file_name=STUDENTFILE;
    }

    else if (choice == 2)
    {
        cout << "请输入职工号：" << endl;
        while (!(cin >> num))
        {
            cout << "职工号应为整数，请重新输入：" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        file_name=TEACHERFILE;
    }


    cout << "请输入姓名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> password;
    if(f.read_check_account(num,name,password,file_name)){
        f.write_account(num, name, password, file_name);
    }
    else{
        cout<<"一个人只可拥有一个账号，不可重复添加"<<endl;
    }
    
}

void admin::view_account()
{
    File f;
    cout << "请选择查看的内容：\n1、查看所有学生\n2、查看所有老师" << endl;
    int choice = 0;
    while (!(cin >> choice) || choice<1 ||choice>2)
    {
        cout << "序号应为整数且为1或2，请重新输入：" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (choice == 1)
    {
        f.read_account(STUDENTFILE);
    }
    else if (choice == 2)
    {
        f.read_account(TEACHERFILE);
    }
   

}

void admin::view_computer_room()
{
    File f;
    f.read_computerRoom();
}

void admin::clear_booking()
{
    File f;
    f.clear_file(ORDERFILE);
}

bool admin::logout()
{
    return true;
}

admin::~admin()
{
}
