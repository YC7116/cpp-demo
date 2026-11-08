#include <iostream>
#include "Add_Contact.h"
#include "Show_Contact.h"
#include "Del_Contact.h"
#include "Sea_Contact.h"
#include "Set_Contact.h"
#include "Cls_Contact.h"
#include "Contacter.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){

    Contacter *c=(Contacter *)malloc(sizeof(Contacter)*MAX_SIZE);
    int choice = 0;
    int lenth=0;
    string str;
  

    while (1)
     {
        cout << "************************" << endl;
        cout << "***** 1、添加联系人 *****" << endl;
        cout << "***** 2、显示联系人 *****" << endl;
        cout << "***** 3、删除联系人 *****" << endl;
        cout << "***** 4、查找联系人 *****" << endl;
        cout << "***** 5、修改联系人 *****" << endl;
        cout << "***** 6、清空联系人 *****" << endl;
        cout << "***** 0、退出通讯录 *****" << endl;
        cout << "************************" << endl;

        cout << "请输入您的选择：";
        cin >> choice;

        switch (choice){
            case 1:
                Add_Contact(c,&lenth);
                break;
            case 2:
                Show_Contact(c,&lenth);
                break;
            case 3:
                int index;
                cout<<"你要删除第几个联系人"<<endl;
                cin.ignore();  
                cin>>index;
                Del_Contact(c,&lenth,index);
                break;
            case 4 :
                char name1[20];
                cout<<"请输入你要查找的人名"<<endl;
                cin.ignore();
                cin>>name1;
                Sea_Contact(c,&lenth,name1);
                break;
            case 5:
                char name[20];
                cout<<"请输入你要设置哪个联系人"<<endl;
                cin.ignore();
                cin>>name;
                Set_Contact(c,&lenth,name);
                break;
            case 6:
                Cls_Contact(c,&lenth);
                break;
            case 0:
                break;
            default:
                break;
        }


        cout << "你是否要继续操作(y/n):";
        cin >> str;

        if (str=="y"){
            continue;
        }
        else if(str=="n"){
            break;
        }
        else{
            cout<<"输入未知字符默认继续"<<endl;
            continue;
        }

    break;    
    }
   
}
