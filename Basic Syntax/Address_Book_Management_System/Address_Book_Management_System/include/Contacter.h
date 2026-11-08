#pragma once // 防止重复包含
#include <string> // 必须包含 string 头文件
#include <iostream>
#define MAX_SIZE 1000
#include  <cstring>
using namespace std;

// 建议直接使用 struct，C++ 中不需要 typedef struct 这种 C 语言写法
struct Contacter {
    char name[20];
    char gender[20];
    int age;
    char number[30];
    char address[90];
};