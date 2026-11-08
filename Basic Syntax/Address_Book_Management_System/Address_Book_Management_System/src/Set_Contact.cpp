#include "Set_Contact.h"
#include <iostream>
#include "Contacter.h"
using namespace std;

void Set_Contact(Contacter *c,int *lenth,char name[]) {
        int choice;

        int index = -1;
        for (int i = 0; i < *lenth; i++) {
            if (strcmp(name, c[i].name) == 0) {
                index = i;
                break;
        }
        }
          
        if(index!=-1) {
            cout<<"请输入你选择修改的信息\n1-->name\n2-->gender\n3-->age\n4-->number\n5-->address:"<<endl;
            cin>>choice;
            switch (choice)
            {
            case 1:{

                char change[20];
                cout<<"请输入你更改该联系人名字为："<<endl;
                cin>>change;
                strcpy(c[index].name,change);
                break;
            }
                
            
            case 2:{

            int change;
            while (1) {
                cout << "请输入你要更改性别为：" << endl;
                cout << "1----->男" << endl;
                cout << "2----->女" << endl;
                cin>>change;
                if(change==1){
                    strcpy(c[index].gender,"男");
                    break;
                }
                else if(change==2){
                    strcpy(c[index].gender,"女");
                    break;
            }

            else{
                cout<<"输入内容不正确，请重新输入"<<endl;
            }

        }
            break;
            }
               
            case 3:{

                int change;
                while (1) {
                    cout<<"请输入年龄："<< endl;
                    cin>>change;
                    if(change<=0 || change>300){
                        cout<<"年龄超出范围，请重新输入"<<endl;
                        continue;
                    }
                c[index].age=change;
                break;
                }
            break;
            }
                 
            case 4:{

                char change[30];
                while (1) {
                    cout<<"请输入你要更改联系电话(11位)为："<< endl;
                    cin>>change;
                    if( strlen(change)!=11){
                        cout<<"你输入的电话位数为"<<strlen(change)<<"应当为11位"<<endl;
                        continue;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
                    }
                    else{
                        int flag=1;
                        for(size_t i=0;i<strlen(change);i++){
                            if(change[i]<48 || change[i]>57){
                                flag=0;
                            break;
                            }
                        }
                        if(flag==0){
                            cout<<"你添加的数字中包含字母，请重新输入"<<endl;
                            continue;
                        }

                    }
                    strcpy(c[index].number,change);
                    break;
                }
            break;
            }
             
            case 5:{

                char change[30];
                cout<<"请输入你更改该联系人的家庭住址为："<<endl;
                cin>>change;
                strcpy(c[index].number,change);
                break;
            }
                

            default:
                break;
            }

        }
        else{
            cout<<"未找到该用户无法设置用户信息"<<endl;
        }
          

}
/*
            if(strcmp(choice,"name")==0){
                char change[20];
                cout<<"请输入你更改该联系人名字为："<<endl;
                cin>>change;
                strcpy(c[index].name,change);
            }
            else if(strcmp(choice,"gender")==0){
                char change[20];
                cout<<"请输入你更改该联系人性别为："<<endl;
                cin>>change;
                strcpy(c[index].gender,change);
            }
            else if(strcmp(choice,"age")==0){
                int change;
                cout<<"请输入你更改该联系人年龄为："<<endl;
                cin>>change;
                c[index].age=change;
            }
            else if(strcmp(choice,"number")==0){
                char change[30];
                cout<<"请输入你更改该联系人点换号码为："<<endl;
                cin>>change;
                strcpy(c[index].number,change);
            }
            else if(strcmp(choice,"address")==0){
                char change[90];
                cout<<"请输入你更改该联系人家庭地址为："<<endl;
                cin>>change;
                strcpy(c[index].address,change);
            }


*/