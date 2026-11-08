#include "File.h"
#include "config.h"
#include "student.h"
#include "teacher.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

File::File()
{
}

void File::f_init(){
    ifstream ifs;
    v.clear();
    order o;
    ifs.open(ORDERFILE);
    if(ifs.is_open()){
        while(ifs>>o.date>>o.time>>o.num>>o.name>>o.room_num>>o.state){
            v.push_back(o);
        }
    }
    ifs.close();

}





void File::write_account(int num, string name, string password, string file_name)
{
    ofstream ofs;
    ofs.open(file_name, ios::app);
    ofs << num << ' ' << name << ' ' << password << endl;
}




void File::read_account(string file_name)
{
    ifstream ifs;
    ifs.open(file_name);
    int num;
    string name;
    string password;
    if (file_name == STUDENTFILE)
    {
        cout << "学生信息如下" << endl;
        while (ifs >> num>> name >> password)
        {
            cout << "学号：" << num << "  姓名：" << name << "  密码：" << password << endl;//这里可以把这个学生信息如下与学号设为变量string从而实现不同情况输出
        }
    }
    else
    {
        cout << "老师信息如下" << endl;
        while (ifs >> num >> name  >> password)
        {
            cout << "职工号：" << num << "  姓名：" << name << "  密码：" << password << endl;
        }
    }
}

bool File::read_check_account(int num,string name,string password,string file_name){
    ifstream ifs;
    ifs.open(file_name);
    int fnum;
    string fname;
    string fpassword;
    while (ifs >> fnum>> fname >> fpassword)
    {
        if(fnum==num){
            
            return false;
        }
    }
    return true;

}

void File::read_computerRoom(){
    ifstream ifs(COMPUTERFILE);
    int c_num;
    int c_capacity;
    while (ifs >> c_num && ifs >> c_capacity)
    {
        cout << "第" << c_num << "号机房能容纳" << c_capacity << "人" << endl;
    }
}


void File::write_order(){
    ofstream ofs(ORDERFILE);
    for (vector<order>::iterator it=v.begin(); it!=v.end(); it++)
    {
        ofs <<it->date << ' '<<it->time << ' '<<it->num<<' '<<it->name<<' '<<it->room_num << ' '<<it->state<<endl;
    }
    ofs.close();
}

void File::read_order(){

}

bool File::read_check_order(string date,string time,int room_num){
    ifstream ifs;
    ifs.open(ORDERFILE);
    string fdate;
    string ftime;
    int fnum;
    string fname;
    int froom_num;
    string fstate;
    while (ifs >> fdate>> ftime >> fnum>>fname>>froom_num>>fstate)
    {
        if(fdate==date && ftime==time && froom_num==room_num){
            return false;
        }
    }
    return true;
}

void File::clear_file(string file_name){
    ofstream ofs;
    ofs.open(file_name);
    cout<<"已清空"<<endl;
    ofs.close();
}

File::~File()
{
}
