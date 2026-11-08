#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class File
{
public:
    File();
    ~File();

    void f_init();

    void write_account(int num, string name, string password, string file_name);

    void write_order();

    void read_account(string file_name);

    bool read_check_account(int num, string name, string password, string file_name);

    bool read_check_order(string date,string time,int room_num);

    void read_order();

    void read_computerRoom();

    void clear_file(string file_name);

    int read_count = 0;
};
