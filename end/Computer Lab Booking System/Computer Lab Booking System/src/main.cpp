#include <iostream>
#include "Person.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"
#include "config.h"
#include "order.h"
#include "File.h"
#include <fstream>

using namespace std;

vector<order> v;

Person *login(string filename, int i_type);
bool subpage(Person *p, int i_type);

int main(int argc, char *argv[])
{
    while (true)
    {
        File f;
        f.f_init();
        int choice = 0;
        cout << "================ 欢迎来到传智播客机房预约系统 ================" << endl;
        cout << "请输入您的身份" << endl;
        cout << "------------------------------------" << endl;
        cout << "|                                  |" << endl;
        cout << "|            1. 学生代表           |" << endl;
        cout << "|            2. 老    师           |" << endl;
        cout << "|            3. 管 理 员           |" << endl;
        cout << "|            0. 退    出           |" << endl;
        cout << "|                                  |" << endl;
        cout << "------------------------------------" << endl;

        while (!(cin >> choice))
        {
            cout << "输入应为整数，请重新输入：" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (choice)
        {
        case 1:
        {
            Person *p = login(STUDENTFILE, 1);
            if (p != nullptr)
            { // 登录失败返回 nullptr，不需要进 subpage
                while (!(subpage(p, 1)));     // 只要没注销，就一直循环
                delete p; // 注销后统一删除
            }
            break;
        }

        case 2:
        {
            Person *p = login(TEACHERFILE, 2);
            if (p != nullptr)
            { // 登录失败返回 nullptr，不需要进 subpage
                while (!(subpage(p, 2)));     // 只要没注销，就一直循环
                delete p; // 注销后统一删除
            }
            break;
        }
        case 3:
        {
            Person *p = login(ADMINFILE, 3);
            if (p != nullptr)
            { // 登录失败返回 nullptr，不需要进 subpage
                while (!(subpage(p, 3)));     // 只要没注销，就一直循环
                delete p; // 注销后统一删除
            }
            break;
        }
        case 0:
        {
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        }
        default:
            break;
        }
    }
}

Person *login(string filename, int i_type)
{
    ifstream ifs;
    ifs.open(filename);
    string fname;
    string fpassword;
    switch (i_type)
    {
    case 1:
    {
        string name;
        string password;
        int stu_num;
        int fstu_num;
        cout << "请输入学号" << endl;
        while (!(cin >> stu_num))
        {
            cout << "学号应为整数，请重新输入：" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "请输入姓名：" << endl;
        cin >> name;
        cout << "请输入密码：" << endl;
        cin >> password;
        bool flag = false;
        while (ifs >> fstu_num && ifs >> fname && ifs >> fpassword)
        {
            if (fstu_num == stu_num && fname == name && fpassword == password)
            {
                flag = true;
            }
        }

        if (flag)
        {
            Person *p = new student(stu_num, name, password);
            return p;
        }
        else
        {
            Person *p = nullptr;
            return p;
        }

        break;
    }
    case 2:
    {
        string name;
        string password;
        int staff_num;
        int fstaff_num;
        cout << "请输入职工号:" << endl;
        while (!(cin >> staff_num))
        {
            cout << "学号应为整数，请重新输入：" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "请输入姓名：" << endl;
        cin >> name;
        cout << "请输入密码：" << endl;
        cin >> password;
        bool flag = false;
        while (ifs >> fstaff_num && ifs >> fname && ifs >> fpassword)
        {
            if (fstaff_num == staff_num && fname == name && fpassword == password)
            {
                flag = true;
            }
        }

        if (flag)
        {
            Person *p = new teacher(staff_num, name, password);
            return p;
        }
        else
        {
            Person *p = nullptr;
            return p;
        }

        break;
    }
    case 3:
    {
        string name;
        string password;
        cout << "请输入用户名：" << endl;
        cin >> name;
        cout << "请输入密码：" << endl;
        cin >> password;
        bool flag = false;
        while (ifs >> fname && ifs >> fpassword)
        {
            if (fname == name && fpassword == password)
            {
                flag = true;
            }
        }

        if (flag)
        {
            Person *p = new admin(name, password);
            return p;
        }
        else
        {
            Person *p = nullptr;
            return p;
        }

        break;
    }

    default:
    {

        break;
    }
    }
    ifs.close();
    return nullptr;
}

bool subpage(Person *p, int i_type)
{
    if (p == nullptr)
    {
        cout << "该用户不存在" << endl;
        return true;
    }

    switch (i_type)
    {
    case 1:
    {
        p->show_menu();
        student *s = (student *)p;
        int choice = 0;
        cout << "请输入您的操作：" << endl;
        while (!(cin >> choice))
        {
            cout << "类型应为整数，请重新输入：" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (choice)
        {
        case 1:
        {
            s->apply_booking();
            break;
        }
        case 2:
        {
            s->my_booking();
            break;
        }
        case 3:
        {
            s->view_booking();
            break;
        }
        case 4:
        {
            s->delete_booking();
            break;
        }
        case 0:
        {
            bool flag = s->logout();
            return flag;
        }

        default:
            break;
        }

        break;
    }
    case 2:
    {
        p->show_menu();
        teacher *t = (teacher *)p;
        int choice = 0;
        cout << "请输入您的操作：" << endl;
        while (!(cin >> choice))
        {
            cout << "类型应为整数，请重新输入：" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (choice)
        {
        case 1:
        {
            t->all_booking();
            break;
        }
        case 2:
        {
            t->check_booking();
            break;
        }
        case 0:
        {
            bool flag = t->logout();
            return flag;
            break;
        }
        default:
            break;
        }
        break;
    }
    case 3:
    {
        p->show_menu();
        admin *a = (admin *)p;
        int choice = 0;
        cout << "请输入您的操作：" << endl;
        while (!(cin >> choice))
        {
            cout << "类型应为整数，请重新输入：" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (choice)
        {
        case 1:
        {
            a->add_account();
            break;
        }
        case 2:
        {
            a->view_account();
            break;
        }
        case 3:
        {
            a->view_computer_room();
            break;
        }
        case 4:
        {
            a->clear_booking();
            break;
        }
        case 0:
        {
            bool flag = a->logout();
            return flag;
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }

    return false;
}
