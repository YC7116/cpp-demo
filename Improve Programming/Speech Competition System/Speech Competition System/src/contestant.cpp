#include "contestant.h"
#include <iostream>
#include <string>

contestant::contestant() {
}

contestant::contestant(string name,int contestant_number){
    this->m_name=name;
    this->m_contestant_number=contestant_number;
}
bool contestant::operator>(const contestant& other) const {
    return this->m_score > other.m_score;  // °´·ÖÊı½µĞò
}
contestant::~contestant() {
}

