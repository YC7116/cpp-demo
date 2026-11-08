#pragma once

#include <iostream>
#include <string>
using namespace std;

class contestant {
public:
    contestant();
    contestant(string name,int contestant_number);
    bool operator>(const contestant& other) const;
    ~contestant();

    string m_name;
    float m_score;
    int m_contestant_number;
};

