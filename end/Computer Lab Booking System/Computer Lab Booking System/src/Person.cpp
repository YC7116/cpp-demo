#include "Person.h"
#include <iostream>
#include <string>
#include <vector>

Person::Person() {
}
Person::Person(string name,string password):name(name),password(password){}
Person::~Person() {
}

