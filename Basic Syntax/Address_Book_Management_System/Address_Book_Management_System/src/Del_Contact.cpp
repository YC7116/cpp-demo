#include "Del_Contact.h"
#include <iostream>
#include "Contacter.h"

using namespace std;

void Del_Contact(Contacter *c,int *lenth,int index) {
    for (int i = index;i<(*lenth) ; i++) {

            if(i!=100) {
                strcpy(c[i-1].name,c[i].name);
                strcpy(c[i-1].gender,c[i].gender);
                c[i-1].age=c[i].age;
                strcpy(c[i-1].address,c[i].address);
                strcpy(c[i-1].number,c[i].number);
            }
            else{

            }

    }
    (*lenth)--;
}
