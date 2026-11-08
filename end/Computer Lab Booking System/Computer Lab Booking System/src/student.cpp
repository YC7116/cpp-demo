#include "student.h"
#include "config.h"
#include "File.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
student::student()
{
}

student::student(int stu_num, string name, string password) : Person(name, password)
{
    this->stu_num = stu_num;
}

void student::show_menu()
{
    cout << "欢迎学生代表：" << this->name << "登录！" << endl;
    cout << "          ----------------------------------" << endl; // 根据图片调整空格
    cout << "          |                                |" << endl;
    cout << "          |           1. 申请预约          |" << endl;
    cout << "          |           2. 查看我的预约      |" << endl;
    cout << "          |           3. 查看所有预约      |" << endl;
    cout << "          |           4. 取消预约          |" << endl;
    cout << "          |           0. 注销登录          |" << endl;
    cout << "          |                                |" << endl;
    cout << "          ----------------------------------" << endl;
}

void student::apply_booking()
{
    File f;
    int c_date;
    int c_time;
    string date;
    string time;
    int room_num;

    cout << "机房开放时间为周一到周五！" << endl;
    cout << "请输入申请预约的时间：\n1、周一\n2、周二\n3、周三\n4、周四\n5、周五" << endl;
    while (!(cin >> c_date) || c_date < 1 || c_date > 5)
    {
        cout << "序号应为整数且在1~5之间，请重新输入：" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    switch (c_date)
    {
    case 1:
        date = "周一";
        break;

    case 2:
        date = "周二";
        break;
    case 3:
        date = "周三";
        break;
    case 4:
        date = "周四";
        break;
    case 5:
        date = "周五";
        break;
    }

    cout << "请输入申请预约的时间段：\n1、上午\n2、下午" << endl;
    while (!(cin >> c_time) || c_time < 1 || c_time > 2)
    {
        cout << "序号应为整数且在1~2之间，请重新输入：" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    switch (c_time)
    {
    case 1:
        time = "上午";
        break;
    case 2:
        time = "下午";
    default:
        break;
    }

    cout << "请选择机房：\n1号机房容量：20\n2号机房容量：50，\n3号机房容量：100" << endl; // 暂时写死，若要后续添加可改
    while (!(cin >> room_num) || room_num < 1 || room_num > 3)
    {
        cout << "机房号应为整数且在1~3之间，请重新输入：" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    
    if(f.read_check_order(date,time,room_num)){
        cout<<"预约提交，审核中"<<endl;
        v.push_back({date, time,this->stu_num,this->name, room_num, UNDERREVIEW});
        f.write_order();
    }
    else{
        cout<<"预约失败，该时间段已被预约"<<endl;
        v.push_back({date, time,this->stu_num,this->name, room_num, FAIL});
        f.write_order();
        
    }
    //先用这个到时候写个读写文件的类，admin还要写检测账号重复功能，这里预约还要防止日期时间重复，重复添加为预约失败
}

int student::my_booking()
{
    int i=1;
    for (vector<order>::iterator it=v.begin(); it!=v.end(); it++)
    {
        if(it->name==this->name && it->num==this->stu_num){
            cout<<i<<"、"<<"预约日期："<<it->date<<"  时段："<<it->time<<"  机房："<<it->room_num<<"  状态："<<it->state<<endl;
            i++;
        }
        
    }
    return i;
    
}

void student::view_booking()
{
    int i=1;
    for (vector<order>::iterator it=v.begin(); it!=v.end(); it++)
    {
            cout<<i<<"、"<<"预约日期："<<it->date<<"  时段："<<it->time<<"  学号："
            <<it->num<<"  名字："<<it->name<<"  机房："
            <<it->room_num<<"  状态："<<it->state<<endl;
        i++;
    }
    
}

void student::delete_booking()
{
    File f;
    int choice=0;
    cout<<"审核中或预约成功的记录可以取消，可取消的记录："<<endl;

    int i=1;
    map<int,vector<order>::iterator> i_index;
    for (vector<order>::iterator it=v.begin(); it!=v.end(); it++)
    {
        if(it->name==this->name && it->num==this->stu_num && (it->state==UNDERREVIEW || it->state==SUCCESS)){
            cout<<i<<"、"<<"预约日期："<<it->date<<"  时段："<<it->time<<"  机房："<<it->room_num<<"  状态："<<it->state<<endl;
            i_index.insert(make_pair(i,it));
            i++;
        }
    }
    cout<<"请输入你要取消的预约："<<endl;
    while (!(cin>>choice) || choice<1 || choice>(int)i_index.size())
    {
        cout<<"取消的预约号应为整数且在1~"<<i_index.size()<<"之间"<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
    }
    
    i_index.at(choice)->state=CANCEL;
    f.write_order();
}   
bool student::logout()
{
    return true;
}

student::~student()
{
}
