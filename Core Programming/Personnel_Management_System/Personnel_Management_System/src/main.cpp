#include "worker_manager.h"
#include "staff.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    worker_manager wm;
    wm.sync_staff_info();
    bool flag = true;
    while (flag)
    {
        
        wm.show_menu();
        
        int choice = 0;
        cout << "请输入你的选择:" << endl;

        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            flag = false;
            cout << "欢迎下次使用" << endl;
            break;
        }
        case 1:
        {
            wm.add();
            break;
        }
        case 2:
        {
            wm.display();
            break;
        }
        case 3:
        {
           int choice = 0;
            cout << "请输入你要选择的删除方式\n" << "1、按职工编号查找\n" << "2、按职工姓名查找" << endl;
            cin >> choice;
            if (choice == 1)
            {
                int n;
                cout << "请输入要删除的职工的编号" << endl;
                cin >> n;
                wm.delet(n);
            }

            else if (choice == 2)
            {
                string n;
                cout << "请输入要删除的职工的姓名" << endl;
                cin >> n;
                wm.delet(n);
            }
            else
            {
                cout << "输入错误" << endl;
            }

            break;
        }
        case 4:
        {
           int choice = 0;
            cout << "请输入你要选择的修改方式\n" << "1、按职工编号修改\n" << "2、按职工姓名修改" << endl;
            cin >> choice;
            if (choice == 1)
            {
                int n;
                cout << "请输入要修改的职工的编号" << endl;
                cin >> n;
                wm.change(n);
            }

            else if (choice == 2)
            {
                string n;
                cout << "请输入要修改的职工的姓名" << endl;
                cin >> n;
                wm.change(n);
            }
            else
            {
                cout << "输入错误" << endl;
            }

            break;
        }
        case 5:
        {
            int choice = 0;
            cout << "请输入你要选择的查找方式\n" << "1、按职工编号查找\n" << "2、按职工姓名查找" << endl;
            cin >> choice;
            if (choice == 1)
            {
                int n;
                cout << "请输入要查找的职工的编号" << endl;
                cin >> n;
                wm.search(n);
            }

            else if (choice == 2)
            {
                string n;
                cout << "请输入要查找的职工的姓名" << endl;
                cin >> n;
                wm.search(n);
            }
            else
            {
                cout << "输入错误" << endl;
            }

            break;
        }

        case 6:
        {
            int choice = 0;
            cout << "请输入你要选择的排序方式\n" << "1、降序\n" << "2、升序" << endl;
            cin >> choice;
            wm.reverse(choice);
            break;
        }

        case 7:
            wm.clear();
            break;

        default:
            break;
        }
    }
}



/*
项目总结，动作相同细节不同用多态
每写一个功能都要先想这个功能我要实现什么最终目标，然后再拆分为每小部分我要实现什么目标，
在实现这个目标的时候要确保代码有普适性，不能只有当下情况代码能运行，也就是要找到那个不变的点
设立的目标要围绕着哪个绝对不变的点走，这样代码在之后就算有更改也不会破化核心




*/