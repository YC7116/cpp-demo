#include "worker_manager.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include "worker_data.h"
using namespace std;
worker_data worker_manager::d;

ostream &operator<<(ostream &cout,const staff& s)
{

    cout << "编号:" << s.number 
        << " 姓名:" << s.name 
       << " 岗位:" << s.job 
       << " 职责:" << s.responsibility();
    return cout;   

}
//-------------------------------------------------------------------------------------------------
worker_manager::worker_manager()
{
}
//--------------------------------------------------------------------------------------------------
void worker_manager::show_menu()
{

    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ ***********" << endl;
    cout << "*************  0.退出管理程序  **************" << endl;
    cout << "*************  1.增加职工信息  **************" << endl;
    cout << "*************  2.显示职工信息  **************" << endl;
    cout << "*************  3.删除离职职工  **************" << endl;
    cout << "*************  4.修改职工信息  **************" << endl;
    cout << "*************  5.查找职工信息  **************" << endl;
    cout << "*************  6.按照编号排序  **************" << endl;
    cout << "*************  7.清空所有文档  **************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}
//----------------------------------------------------------------------------------------
//将缓存数组与文件同步
void worker_manager::sync_staff_info()
{
    //先对内部数组初始化
    for (size_t i = 0; i < d.lenth; i++)
    {
        delete d.s[i];
        d.s[i]=nullptr;
    }
    
    ifstream ifs;
    ifs.open("worker_manager.txt");
    char buf[1024];


    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    int index=0;
    while (ifs.getline(buf, sizeof(buf)))
    {

        // 提取一行中的编号，姓名，工作：
        int number_arr[40];
        for (int i = 0; i < 40; i++)
        {
            number_arr[i] = -1;
        } // 初始化为-1

        char name_arr[40]={0};
        int flag = 0;
        size_t start = 0;
        for (size_t i = 0; i < strlen(buf); i++)
        {
            if (buf[i] == ' ')
            {
                flag++;
                start = i + 1;
                continue;
            }

            switch (flag)
            {
            case 0:
            {
                number_arr[i - start] = (buf[i] - '0');
                break;
            }

            case 1:
            {
                name_arr[i - start] = buf[i];
                break;
            }

            default:
            {
                break;
            }
            }
        }

        // 转化数字数组，字符数组为整型与字符串:
        int number = 0;

        int num_len = 0;
        int i = 0;
        while (number_arr[i] != -1)
        {
            i++;
            num_len++;
        } // 获取整型数组的长度
        for (size_t i = 0; i < num_len; i++)
        {
            number = number * 10 + number_arr[i];
        }

        string name = string(name_arr);

        int job = (buf[strlen(buf) - 1] - '0');

        // 根据工作创建相应类型对象，再用基类指针指向对象
        staff *s = nullptr;
        switch (job)
        {
        case 1:
        {
            s = new employee(number, name, job);
            break;
        }
        case 2:
        {
            s = new manager(number, name, job);
            break;
        }

        case 3:
        {
            s = new boss(number, name, job);
            break;
        }
        default:
        {
            break;
        }
        }
        d.s[index]=s;
        index++;
        d.lenth=index;
    }
    ifs.close();
}
//---------------------------------------------------------------------------------------------
//添加
void worker_manager::add()
{
    int num = 0;
    cout << "请输入你要添加的职工的数量" << endl;
    cin >> num;
    for (size_t i = 0; i < num; i++)
    {
        int number;
        string name;
        int job;
        cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
        cin >> number;

        cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
        cin >> name;

        cout << "请输入第" << i + 1 << "个新职工的岗位\n"
             << "1.普通职工\n"
             << "2.经理\n"
             << "3.老板" << endl;
        cin >> job;
        staff *s = nullptr;
        switch (job)
        {
        case 1:
        {
            s = new employee(number, name, job);
            break;
        }
        case 2:
        {
            s = new manager(number, name, job);
            break;
        }

        case 3:
        {
            s = new boss(number, name, job);
            break;
        }

        default:
            cout << "输入的岗位不正确" << endl;
            break;
        }
        d.add_data(s);
    }
    overwrite();
}
//---------------------------------------------------------------------------------------------------
//展示
void worker_manager::display()
{
    
    for (size_t i = 0; i < d.lenth; i++)
    {

        cout<<"第"<<i+1<<"个员工"<<*d.s[i]<<endl;
    }
     // 运算符重载
}
//----------------------------------------------------------------------------------------------------
//删除
void worker_manager::delet(int number)
{
    int p = 0;
    for (size_t i = 0; i < d.lenth; i++)
    {
        if (d.s[i]->number == number)
        {
            p = i;
            break;
        }
        else
        {
            p = -1;
        }
    }
    if (p != -1)
    {
        for (size_t i = p; i < d.lenth; i++)
        {
            d.s[i] = d.s[i + 1];
        }
        d.lenth--;
    }
    else
    {
        cout << "删除失败，未找到该职工" << endl;
    }
    overwrite();
}
void worker_manager::delet(string name)
{
    int p = 0;
    for (size_t i = 0; i < d.lenth; i++)
    {
        if (d.s[i]->name == name)
        {
            p = i;
            break;
        }
        else
        {
            p = -1;
        }
    }
    if (p != -1)
    {
        for (size_t i = p; i < d.lenth; i++)
        {
            d.s[i] = d.s[i + 1];
        }
        d.lenth--;
    }
    else
    {
        cout << "删除失败，未找到该职工" << endl;
    }
    overwrite();
}
//---------------------------------------------------------------------------------------------------------
//更改
void worker_manager::change(int number)
{
    int p = 0;
    for (size_t i = 0; i < d.lenth; i++)
    {
        if (d.s[i]->number == number)
        {
            p = i;
            break;
        }
        else
        {
            p = -1;
        }
    }
    if (p ==-1)
    {
        cout << "未找到该职工修改失败" << endl;
    }
    else
    {
        cout << "查到该职工信息为："<<endl;
        cout<<*d.s[p]<<endl;
        cout << "请输入新编号：" << endl;
        cin >> d.s[p]->number;
        cout << "请输入新姓名：" << endl;
        cin >> d.s[p]->name;
        cout << "请输入新岗位：" << endl;
        cin >> d.s[p]->job;
    }
    overwrite();
}

void worker_manager::change(string name)
{
    int p = 0;
    for (size_t i = 0; i < d.lenth; i++)
    {
        if (d.s[i]->name == name)
        {
            p = i;
            break;
        }
        else
        {
            p = -1;
        }
    }
    if (p ==-1)
    {
        cout << "未找到该职工修改失败" << endl;
    }
    else
    {
        cout << "查到该职工信息为："<<endl;
        cout<<*d.s[p]<<endl;
        cout << "请输入新编号：" << endl;
        cin >> d.s[p]->number;
        cout << "请输入新姓名：" << endl;
        cin >> d.s[p]->name;
        cout << "请输入新岗位：" << endl;
        cin >> d.s[p]->job;
    }
    overwrite();

}

//-------------------------------------------------------------------------------
//查找
void worker_manager::search(int number)
{
    int p = 0;
    for (size_t i = 0; i < d.lenth; i++)
    {
        if (d.s[i]->number == number)
        {
            p = i;
            break;
        }
        else
        {
            p = -1;
        }
    }
    if (p ==-1)
    {
        cout << "未找到该职工" << endl;
    }
    else
    {
        cout << "查到该职工信息为："<<endl;
        cout<<*d.s[p]<<endl;
    }
}

void worker_manager::search(string name)
{
    int p = 0;
    for (size_t i = 0; i < d.lenth; i++)
    {
        if (d.s[i]->name == name)
        {
            p = i;
            break;
        }
        else
        {
            p = -1;
        }
    }
    if (p ==-1)
    {
        cout << "未找到该职工" << endl;
    }
    else
    {
        cout << "查到该职工信息为："<<endl;
        cout<<*d.s[p]<<endl;
    }
}
//-----------------------------------------------------------------------------------------------------
//排序
void worker_manager::reverse(int choice)
{
    if (choice == 1)
    { // 降序
        for (size_t i = 0; i < d.lenth; i++)
        {
            for (size_t j = i + 1; j < d.lenth; j++)
            {
                if ((d.s[i]->number) < (d.s[j]->number))
                {
                    staff *s = nullptr;
                    s = d.s[j];
                    d.s[j] = d.s[i];
                    d.s[i] = s;
                }
            }
        }
        cout << "排列成功，排列结果为：" << endl;
        display();
    }
    else if (choice == 2)
    { // 升序
        for (size_t i = 0; i < d.lenth; i++)
        {
            for (size_t j = i + 1; j < d.lenth; j++)
            {
                if ((d.s[i]->number) > (d.s[j]->number))
                {
                    staff *s = nullptr;
                    s = d.s[j];
                    d.s[j] = d.s[i];
                    d.s[i] = s;
                }
            }
        }
        cout << "排列成功，排列结果为：" << endl;
        display();
    }
    else
    {
        cout << "输入不正确" << endl;
    }
    overwrite();
}
//---------------------------------------------------------------------------------------------
//清空
void worker_manager::clear()
{
    int choice = 0;
    cout << "确定清空？\n"
         << "1、确定\n"
         << "2、返回" << endl;
    cin >> choice;
    if (choice == 1) {
        for (int i = 0; i < d.lenth; i++) {
            delete d.s[i];
            d.s[i] = nullptr;
        }
        d.lenth = 0;
        ofstream ofs("worker_manager.txt", ios::out);
        ofs.close();
        cout << "清空成功！" << endl;
    }
}
//-----------------------------------------------------------------------------------------------------------------
//文件覆盖写与追加写
void worker_manager::overwrite()
{
    ofstream ofs;
    ofs.open("worker_manager.txt", ios::out);
    for (size_t i = 0; i < worker_manager::d.lenth; i++)
    {
        ofs << worker_manager::d.s[i]->number << " " << worker_manager::d.s[i]->name << " " << worker_manager::d.s[i]->job << endl;
    }

    ofs.close();
}


worker_manager::~worker_manager()
{
}
