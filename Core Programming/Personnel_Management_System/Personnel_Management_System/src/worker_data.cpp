#include "worker_data.h"
#include <iostream>
#include <string>
#include "boss.h"
#include "manager.h"
#include "employee.h"

worker_data::worker_data()
{
}

void worker_data::add_data(staff *staff)
{
    s[lenth] = staff;
    lenth++;
}
//可以不用写worker_data这个数组直接定义到worker_manager中就可以了，然后这个s也不要硬编码为多少在添加时创建一个新的数组大小是原数组加上需要加的人数然后再用成员指针指向
//新开辟区域释放原开辟区域，这样就可以有多少人数组长度就是多少，初始化统计文件统计有多少编号就有多少人
worker_data::~worker_data()
{
    
}
