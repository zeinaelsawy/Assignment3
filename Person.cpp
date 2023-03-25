#include "Person.hpp"
#include <string>
using namespace std;

Person::Person()
{
    name = "";
    id = 0;
    age = 0;
}

void Person::setName(string n)
{
    name = n;
}

void Person::setId(int num)
{
    id = num;
}

void Person::setAge(int num)
{
    age = num;
}

string Person::getName()
{
    return name;
}

int Person::getId()
{
    return id;
}

int Person::getAge()
{
    return age;
}

void Person::printInfo()
{
    cout<< "Name: " << name << endl;
    cout<<"Age: " << age << endl;
    cout<<"ID: " << id << endl;
}
