#include "Sea_Contact.h"
#include <iostream>
#include "Contacter.h"
using namespace std;

Contacter Sea_Contact(Contacter *c,int *lenth,char name[]) {
        for(int i=0;i<*(lenth);i++){
            if(strcmp(name,c[i].name)==0){
                cout<<"找到该用户为第"<< i+1 <<"个,"<<"电话号码为："<<c[i].number<<endl;
                return c[i];
            }
        }
        Contacter empty = {0};
        return empty;
}
