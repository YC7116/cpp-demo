#pragma once
#include <vector>
#include <string>
using namespace std;

typedef struct order
{
    string date;
    string time;
    int num;
    string name;
    int room_num;
    string state;
}order;


extern vector<order> v;
//周一 上午 1 张三 2 预约已取消