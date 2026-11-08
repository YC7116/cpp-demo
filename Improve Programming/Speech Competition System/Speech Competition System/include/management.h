#pragma once
#include "contestant.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

class management {
public:
    management();


    void start_contest();

    void initialize(int session);

    void random_draw(vector<contestant>& v);

    void grouping();

    void print_v(vector<contestant>& v);

    void judgescore(vector<contestant>& v);

    void m_sort(vector<contestant>& v);

    vector<contestant> advance(vector<contestant>& v);

    vector<contestant> merge(vector<contestant>& v1,vector<contestant>& v2);

    void print_cn(vector<contestant>& v);

    void read_file();

    void write_file(vector<contestant> &v);

    void clear_file();
    
    ~management();

    vector<contestant> v_con;
    vector<contestant> v_group1;
    vector<contestant> v_group2;
    vector<map<int,float>> v_map;
    int c_number=12;
    int session=0;
    string e_name="ABCDEFGHIJKL";
    map<int,float> n_s;
    
};

