#include "Show_Contact.h"
#include <iostream>
#include "Contacter.h"
using namespace std;

void Show_Contact(Contacter *c,int *lenth) {
    for(int i=0;i<*(lenth);i++){
        cout<<"---------------------"<<endl;
        cout<<"名字："<<c[i].name<<endl<<"性别："<<c[i].gender<<endl<<"年龄："<<c[i].age<<endl<<"电话号码："<<c[i].number<<endl<<"家庭地址："<<c[i].address<<endl;
        cout<<"---------------------"<<endl;
    }
}
