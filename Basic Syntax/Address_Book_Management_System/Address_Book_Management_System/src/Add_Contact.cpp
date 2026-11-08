#include "Add_Contact.h"
#include <iostream>
#include "Contacter.h"
using namespace std;

void Add_Contact(Contacter *c,int *lenth) {
    if(*lenth>=0 && *lenth<=MAX_SIZE) {
        int age=0;
        char number[30];
        int gender;
        int length = *lenth;
        cout<<"请输入姓名："<< endl;
        cin>>c[length].name;


        while (1) {
            cout << "请输入性别：" << endl;
            cout << "1----->男" << endl;
            cout << "2----->女" << endl;
            cin>>gender;
            if(gender==1){
                strcpy(c[length].gender,"男");
                 break;
            }
            else if(gender==2){
                strcpy(c[length].gender,"女");
                break;
            }
            else{
                cout<<"输入内容不正确，请重新输入"<<endl;
            }

        }


        while (1) {
            cout<<"请输入年龄："<< endl;
            cin>>age;
            if(age<=0 || age>300){
                cout<<"年龄超出范围，请重新输入"<<endl;
                continue;
            }
            c[length].age=age;
            break;
        }


        while (1) {
            cout<<"请输入联系电话(11位)："<< endl;
            cin>>number;
            if( strlen(number)!=11){
                cout<<"你输入的电话位数为"<<strlen(number)<<"应当为11位"<<endl;
                continue;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
            }
            else{
                int flag=1;
                for(size_t i=0;i<strlen(number);i++){
                    if(number[i]<48 || number[i]>57){
                        flag=0;
                        break;
                    }
                }
                if(flag==0){
                    cout<<"你添加的数字中包含字母，请重新输入"<<endl;
                    continue;
                }

            }
            strcpy(c[length].number,number);
            break;
        }
    

        cout<<"请输入家庭住址："<< endl;
        cin>>c[length].address;
        (*lenth)++; 
    }
    else{
        cout<<"通化录已满无法继续添加"<<endl;
    }  // 先解引用，再对解引用的值自增
}
/*cout<<"请输入姓名：";
    cin>>c->name;
    cout<<"请输入性别";
    cin>>c->gender;
    cout<<"请输入年龄";
    cin>>c->age;
    cout<<"请输入联系电话";
    cin>>c->number;
    cout<<"请输入家庭住址";
    cin>>c->address;*/