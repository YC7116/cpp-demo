#include "management.h"
#include "contestant.h"
#include "main.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>

using namespace std;

management::management()
{
}

void management::start_contest()
{
}

// 需要读取文本获取比赛时第几届的，从而来初始化编号
void management::initialize(int session)
{
    this->session = session;
    int init_num = 10001 + session * 12;
    for (size_t i = 0; i < (size_t)this->c_number; i++)
    {
        string name = "选手";

        name += this->e_name[i];
        int number = (init_num + i);
        contestant c = contestant(name, number);
        v_con.push_back(c);
    }
}

void management::random_draw(vector<contestant> &v)
{
    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);
}

void management::print_v(vector<contestant> &v)
{
    for (vector<contestant>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ' ';
    }
}

void management::print_cn(vector<contestant> &v)
{
    for (size_t i = 0; i < (size_t)v.size(); i++)
    {
        cout << v[i].m_contestant_number << ' ';
    }
}

void management::grouping()
{
    vector<contestant>::iterator it;
    it = (this->v_con).begin() + c_number / 2;
    this->v_group1.assign(this->v_con.begin(), it);
    this->v_group2.assign(it, this->v_con.end());
}

void management::judgescore(vector<contestant> &v)
{
    for (size_t i = 0; i < (size_t)v.size(); i++)
    {
        float a_score = 0;
        float sum = 0;
        for (int j = 0; j < 10; j++)
        {
            int score = rand() % 31 + 70;
            sum += score;
            a_score = sum / 10.0f;
        }
        v[i].m_score = a_score;
    }
}

vector<contestant> management::advance(vector<contestant> &v)
{
    vector<contestant> v_advance;
    for (vector<contestant>::const_iterator it = v.begin(); it != v.begin() + 3; it++)
    {
        v_advance.push_back(*it);
    }
    return v_advance;
}

vector<contestant> management::merge(vector<contestant> &v1, vector<contestant> &v2)
{
    vector<contestant> v_merge;
    for (vector<contestant>::const_iterator it = v1.begin(); it != v1.end(); it++)
    {
        v_merge.push_back(*it);
    }

    for (vector<contestant>::const_iterator it = v2.begin(); it != v2.end(); it++)
    {
        v_merge.push_back(*it);
    }
    return v_merge;
}

void management::m_sort(vector<contestant> &v)
{
    sort(v.begin(), v.end(), greater<contestant>());
}

void management::read_file()
{
    ifstream ifs;
    int flag = 0;
    ifs.open("speech.csv");
    char buf[1024] = {0};
    while (ifs.getline(buf, sizeof(buf)))
    {
        string s;
        int init_num = 0;
        float score = 0;
        for (size_t i = 0; buf[i] !='\0'; i++)
        {
            
            if (buf[i] == ',')
            {
                flag++;
                if (flag != 0 && flag % 2 == 1)
                {
                    init_num = stoi(s);
                }
                else if (flag != 0 && flag % 2 == 0)
                {
                    score = stof(s);
                }
                if (init_num != 0 && score != 0)
                {
                    pair<int, float> p(init_num, score);
                    n_s.insert(p);
                    init_num=0;
                    score=0.0f;
                }
                s.clear();
            }
            else
            {
                s += buf[i];
            }
        }
        v_map.push_back(n_s);
        n_s.clear();
        session++;
    }
}

void management::write_file(vector<contestant> &v)
{
    ofstream ofs;
    ofs.open("speech.csv",ios::app);
    for (vector<contestant>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        ofs << (*it).m_contestant_number << "," << (*it).m_score << ",";
    }
    ofs<<endl;
}

void management::clear_file()
{
    ofstream ofs;
    ofs.open("speech.csv");
}

management::~management()
{
}
