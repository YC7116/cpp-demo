#include <iostream>
#include "contestant.h"
#include "management.h"
#include "main.h"
#include <string>
#include <algorithm>
using namespace std;

ostream &operator<<(ostream &cout, const contestant &c)
{
    cout << "编号：" << c.m_contestant_number << "姓名：" << c.m_name << "成绩：" << c.m_score << endl;
    return cout;
}

int main(int argc, char *argv[])
{
    // management m;
    // m.initialize(1);
    // size_t count=m.v_con.size();
    // for (size_t i = 0; i <count; i++)
    // {
    //     cout<<m.v_con[i]<<endl;
    // }
    // cout<<"213"<<endl;
    // return 0;
    bool flag = true;
    while (true)
    {
        management m;
        m.read_file();
        cout << "****************** 欢迎参加演讲比赛 ******************\n"
             << "      ************* 1.开始演讲比赛 *************\n"
             << "      ************* 2.查看往届记录 *************\n"
             << "      ************* 3.清空比赛记录 *************\n"
             << "      ************* 0.退出比赛程序 *************\n"
             << "******************************************************" << endl;
        int choice = 0;
        cout << "请输入你的选择：" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            m.initialize(m.session);
            cout << "第" << m.session + 1 << "届演讲比赛现在开始！" << endl;
            cout << "第<< 1 >>轮比赛选手正在抽签" << endl;
            cout << "-------------------" << endl;
            cout << "抽签后演讲顺序如下：" << endl;
            m.random_draw(m.v_con);
            m.print_cn(m.v_con);
            cout << "\n-------------------" << endl;
            system("pause");
            m.grouping();
            m.judgescore(m.v_group1);
            m.judgescore(m.v_group2);
            cout << "-------- 第1轮正式比赛开始： --------\n"
                 << endl;
            cout << "第1小组比赛名次：" << endl;
            m.m_sort(m.v_group1);
            m.print_v(m.v_group1);

            cout << "第2小组比赛名次：" << endl;
            m.m_sort(m.v_group2);
            m.print_v(m.v_group2);
            cout << "-------- 第1轮比赛完毕： --------\n"
                 << endl;
            system("pause");
            vector<contestant> v_advance1 = m.advance(m.v_group1);
            vector<contestant> v_advance2 = m.advance(m.v_group2);
            vector<contestant> v_merge = m.merge(v_advance1, v_advance2);
            cout << "-------- 第1轮晋级选手信息如下： --------" << endl;
            m.print_v(v_merge);

            /*
            第 << 2 >> 轮比赛选手正在抽签
            -------------------
            抽签后演讲顺序如下：
            10005 10008 10007 10012 10006 10003
            -------------------*/
            cout << "第 << 2 >> 轮比赛选手正在抽签\n"
                 << "-------------------\n"
                 << "抽签后演讲顺序如下：\n"
                 << endl;
            m.random_draw(v_merge);
            m.judgescore(v_merge);
            m.print_cn(v_merge);
            cout << "\n-------------------" << endl;
            system("pause");
            cout << "-------- 第2轮正式比赛开始： --------" << endl;
            cout << "第1小组比赛名次：" << endl;
            m.m_sort(v_merge);
            m.print_v(v_merge);
            cout << "-------- 第2轮比赛完毕： --------\n"
                 << endl;
            system("pause");

            vector<contestant> v_advance3 = m.advance(v_merge);
            cout << "-------- 第2轮晋级选手信息如下： --------" << endl;
            m.print_v(v_advance3);
            m.write_file(v_advance3);
            break;
        }

        case 2:
        {
            int i = 0;

            vector<string> v = {"冠军", "亚军", "季军"};
            for (map<int, float> rec : m.v_map)
            {
                // map 是按键（选手编号）升序排列的，直接遍历得到的是编号顺序，
                // 与成绩高低无关，所以这里先按成绩从高到低排序再输出。
                vector<pair<int, float>> rank(rec.begin(), rec.end());
                sort(rank.begin(), rank.end(),
                     [](const pair<int, float> &a, const pair<int, float> &b)
                     {
                         if (a.second != b.second)
                             return a.second > b.second;   // 成绩高的排前面
                         return a.first < b.first;         // 成绩相同时编号小的在前
                     });

                cout << "第" << i + 1 << "届";
                for (size_t j = 0; j < rank.size() && j < v.size(); j++)
                {
                    cout << v[j] << "编号：" << rank[j].first
                         << "得分：" << rank[j].second << ' ';
                }
                cout << endl;
                i++;
            }
            // for(int i=0;i<(int)m.v_map.size();i++){
            //     cout<<"第"<<i+1<<"届"<<" 冠军编号："<<m.v_map[i]<<" 得分："<<m.v_map[i][1]<<' ';
            // }
            break;
        }
        case 3:
        {
            int choice = 0;
            cout << "请问是否确认清空：\n" <<"1、确认\n"<<"2、不清空\n"<< endl;
            cin >> choice;
            if (choice == 2)
            {
            }
            else if(choice==1)
            {
                m.clear_file();
                cout<<"已成功清空文件"<<endl;
            }
            else
            {

            }
            break;
        }
        case 0:
        {
            flag = false;
            break;
        }
        }
        if (!flag)
        {
            break;
        }
    }
}
